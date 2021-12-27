#pragma once
#include <tuple>
#include <sstream>
#include <vector>
#include "InvalidNumberOfArguments.h"
#include "ParserError.h"

namespace {
    template<class Ch, class Tr, int index, typename PrintT, typename... Args>
    struct GoThroughTuple_Print {
        static int const size = std::tuple_size<std::tuple<Args...>>::value;
        static void Next(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...>& tuple, PrintT print) {
            GoThroughTuple_Print<Ch, Tr, index - 1, PrintT, Args...>::Next(os, tuple, print);
            print(index, size, os, std::get<index>(tuple));
        }
    };

    template<class Ch, class Tr, typename PrintT, typename... Args>
    struct GoThroughTuple_Print<Ch, Tr, 0, PrintT, Args...> {
        static int const size = std::tuple_size<std::tuple<Args...>>::value;
        static void Next(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...>& tuple, PrintT print) {
            print(0, size, os, std::get<0>(tuple));
        }
    };

    template<class Ch, class Tr, typename PrintT, typename... Args>
    void Print(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...>& tuple, PrintT print) {
        int const size = std::tuple_size<std::tuple<Args...>>::value;
        GoThroughTuple_Print<Ch, Tr, size - 1, PrintT, Args...>::Next(os, tuple, print);
    }

    struct PrintT {
        template<class Ch, class Tr, typename T>
        void operator()(int index, int size, std::basic_ostream<Ch, Tr>& os, T &&t) {
            if (index == size - 1) {
                os << t;
            }
            else {
                os << t << ',';
            }
        }
    };

    template<class Ch, class Tr, typename... Args>
    std::basic_ostream<Ch, Tr>& operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...>& tuple) {
        Print(os, tuple, PrintT());
    }
}

namespace {
    template<typename T>
    bool Convert(const std::string& column, T& out, int line_number, int index, int size) {
        std::stringstream stream(column);
        stream >> out;
        std::stringstream a;
        a << out;
        if (column != a.str()) {
            throw ParserError(line_number, index + 1);
        }
        return true;
    }

    template<>
    bool Convert<std::string>(const std::string& column, std::string& out, int line_number, int index, int size) {
        out = column;
        return true;
    }

    template<int index, int size, typename... Args>
    struct GoThroughTuple_Read {
         static void Next(std::vector<std::string>& line, std::tuple<Args...>& tuple, int line_number) {
            GoThroughTuple_Read<index - 1, size, Args...>::Next(line, tuple, line_number);
            Convert(line[index], std::get<index>(tuple), line_number, index, size);
        }
    };

    template<int size, typename... Args>
    struct GoThroughTuple_Read<0, size, Args...> {
         static void Next(std::vector<std::string>& line, std::tuple<Args...>& tuple, int line_number) {
             Convert(line[0], std::get<0>(tuple), line_number, 0, size);
        }
    };

    template<typename... Args>
    void Read(std::istream& is, std::tuple<Args...>& tuple, char row_delim, char col_delim, int line_number) {
        int const size = std::tuple_size<std::tuple<Args...>>::value;

        std::string buf;
        getline(is, buf, row_delim);
        std::stringstream stream(buf);
        std::vector<std::string> line;

        int count = 0;
        while (stream.peek() != EOF) {
            std::string column;
            getline(stream, column, col_delim);
            line.push_back(column);
            count += 1;
        }

        if (count != size) {
            throw InvalidNumberOfArguments(line_number, count);
        }

        GoThroughTuple_Read<size - 1, size, Args...>::Next(line, tuple, line_number);
    }
}


template<typename... Args>
class CSVParser {
public:
    explicit CSVParser(std::istream& istream, int skip, char row_delim = '\n', char col_delim = ',') : istream(istream), skip(skip), row_delim(row_delim), col_delim(col_delim) {
        std::string buf;
        for (int i = 0; i < skip; ++i) {
            getline(istream, buf, row_delim);
        }
    };

    class Iterator {
    public:
        using iterator_category = std::input_iterator_tag;
        using value_type = std::tuple<Args...>;
        using pointer = value_type*;
        using reference = value_type&;

        explicit Iterator(CSVParser<Args...>* parser = nullptr) : parser(parser) {
            if (parser != nullptr) {
                line_number = parser->skip + 1;
                Read(parser->istream, current_tuple, parser->row_delim, parser->col_delim, line_number);
            }
        }

        reference operator*() {
            return current_tuple;
        }

        Iterator& operator++() {
            if (parser->istream.peek() == EOF || parser == nullptr) {
                parser = nullptr;
                return *this;
            }
            line_number += 1;
            Read(parser->istream, current_tuple, parser->row_delim, parser->col_delim, line_number);
            return *this;
        }

        friend bool operator==(const Iterator& a, const Iterator& b) { return (a.parser == b.parser && a.curr == b.curr); }
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.parser != b.parser; }

    private:
        CSVParser<Args...>* parser;
        value_type current_tuple;
        int line_number;
    };

    Iterator begin() {
        return Iterator(this);
    }
    Iterator end() {
        return Iterator();
    }

private:
    std::istream& istream;
    char row_delim;
    char col_delim;
    int skip;
};

