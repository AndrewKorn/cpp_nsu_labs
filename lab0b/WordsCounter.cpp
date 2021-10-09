#include "WordsCounter.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <thread>

WordsCounter::WordsCounter(std::string input_file, std::string output_file) {
    this->input_file = input_file;
    this->output_file = output_file;
}

void WordsCounter::AddWord(std::string word) {
    if (map_of_words.find(word) == map_of_words.end()) {
        list_of_words.push_back(word);
    }
    map_of_words[word] += 1;
    words_count += 1;
}

void WordsCounter::DivideString(std::string words) {
    int begin_idx = 0, word_len = 0;
    for (int i = 0; i < words.size(); ++i) {
        if (isalpha(words[i]) || isdigit(words[i])) {
            word_len += 1;
        }
        else {
            if (word_len != 0) {
                std::string new_word = words.substr(begin_idx, word_len);
                AddWord(new_word);

            }
            begin_idx = i + 1;
            word_len = 0;
        }
    }
    if (word_len != 0) {
        std::string new_word = words.substr(begin_idx, word_len);
        AddWord(new_word);
    }
}

bool WordsCounter::Comparator(std::string first, std::string second) {
    return map_of_words[first] > map_of_words[second];
}

void WordsCounter::ReadFile() {
    std::ifstream file;
    file.open(this->input_file);

    std::string words;
    while (file) {
        getline(file, words);
        DivideString(words);
    }
}

void WordsCounter::WriteFile() {
    list_of_words.sort(bind(&WordsCounter::Comparator, this, std::placeholders::_1, std::placeholders::_2));
    std::ofstream file;
    file.open(this->output_file);
    file << "Word;Frequency;Frequency(%)" << std::endl;
    for (auto &word : list_of_words) {
        file << word << "; " << map_of_words[word] << "; " << map_of_words[word] / (double)words_count * 100 << std::endl;
    }
    file.close();
}