#include <string>
#include <map>
#include <list>
#pragma once

class WordsCounter {
private:
    int words_count = 0;
    std::string input_file;
    std::string  output_file;
    std::map<std::string, int> map_of_words;
    std::list<std::string> list_of_words;

    void DivideString(std::string words);
    void AddWord(std::string word);
    bool Comparator(std::string first, std::string second);

public:
    WordsCounter(std::string input_file, std::string output_file);
    void ReadFile();
    void WriteFile();
};