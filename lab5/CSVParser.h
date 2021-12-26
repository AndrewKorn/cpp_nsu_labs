#pragma once
#include <tuple>
#include <sstream>

namespace {
    template<class Ch, class Tr, int index, typename PrintT, typename... Args>
    struct GoThroughTuple_Print {
        static int const size = std::tuple_size<std::tuple<Args...>>::value;
        static void Next(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...>& t, PrintT print) {
            GoThroughTuple_Print<Ch, Tr, index - 1, PrintT, Args...>::Next(os, t, print);
            print(index, size, os, std::get<index>(t));
        }
    };

    template<class Ch, class Tr, typename PrintT, typename... Args>
    struct GoThroughTuple_Print<Ch, Tr, 0, PrintT, Args...> {
        static int const size = std::tuple_size<std::tuple<Args...>>::value;
        static void Next(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...>& t, PrintT print) {
            print(0, size, os, std::get<0>(t));
        }
    };

    template<class Ch, class Tr, typename PrintT, typename... Args>
    void Print(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...>& t, PrintT print) {
        int const size = std::tuple_size<std::tuple<Args...>>::value;
        GoThroughTuple_Print<Ch, Tr, size - 1, PrintT, Args...>::Next(os, t, print);
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
    std::basic_ostream<Ch, Tr>& operator<<(std::basic_ostream<Ch, Tr>& os, std::tuple<Args...>& t) {
        Print(os, t, PrintT());
    }
}

namespace {
    template<class T>
    bool Convert(const std::string& column, T& out) {
        std::stringstream stream(column);
        stream >> out;
        return true;
    }

    template<int index, int size, typename... Args>
    struct GoThroughTuple_Read {
        static void Next(std::istream& is, std::tuple<Args...>& t, char row_delim, char col_delim) {
            std::string buf;
            GoThroughTuple_Read<index - 1, size, Args...>::Next(is, t, row_delim, col_delim);
            if (index == size - 1) {
                getline(is, buf, row_delim);
            }
            else {
                getline(is, buf, col_delim);
            }
            Convert(buf, std::get<index>(t));
        }
    };

    template<int size, typename... Args>
    struct GoThroughTuple_Read<0, size, Args...> {
        static void Next(std::istream& is, std::tuple<Args...>& t, char row_delim, char col_delim) {
            std::string buf;
            getline(is, buf, col_delim);
            Convert(buf, std::get<0>(t));
        }
    };

    template<typename... Args>
    void Read(std::istream& is, std::tuple<Args...>& t, char row_delim, char col_delim) {
        int const size = std::tuple_size<std::tuple<Args...>>::value;
        GoThroughTuple_Read<size - 1, size, Args...>::Next(is, t, row_delim, col_delim);
    }
}


template<typename... Args>
class CSVParser {
public:
    explicit CSVParser(std::istream& istream, int skip, char row_delim = '\n', char col_delim = ',') : istream(istream), row_delim(row_delim), col_delim(col_delim) {
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
                Read(parser->istream, curr, parser->row_delim, parser->col_delim);
            }
        }
        reference operator*() {
            return curr;
        }
        Iterator& operator++() {
            if (parser->istream.peek() == EOF) {
                parser = nullptr;
                return *this;
            }
            Read(parser->istream, curr, parser->row_delim, parser->col_delim);
            return *this;
        }
        friend bool operator==(const Iterator& a, const Iterator& b) { return (a.parser == b.parser && a.curr == b.curr); }
        friend bool operator!=(const Iterator& a, const Iterator& b) { return a.parser != b.parser; }

    private:
        CSVParser<Args...>* parser;
        value_type curr;
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
};

