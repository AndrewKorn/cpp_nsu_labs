#include <string>
#include <map>
#include <list>
#pragma once

using namespace std;

class WordsCounter {
private:
    int words_count = 0;
    string input_file;
    string  output_file;
    map<string, int> map_of_words;
    list<string> list_of_words;

    void DivideString(string words);
    void AddWord(string word);
    bool Comparator(string first, string second);

public:
    WordsCounter(string input_file, string output_file);
    void ReadFile();
    void WriteFile();
};