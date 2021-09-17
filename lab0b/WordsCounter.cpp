#include "WordsCounter.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <thread>

using namespace std;

WordsCounter::WordsCounter(std::string input_file, std::string output_file) {
    this->input_file = input_file;
    this->output_file = output_file;
}

void WordsCounter::AddWord(string word) {
    if (this->map_of_words.find(word) == this->map_of_words.end()) {
        this->list_of_words.push_back(word);
    }
    this->map_of_words[word] += 1;
    this->words_count += 1;
}

void WordsCounter::DivideString(string words) {
    int begin_idx = 0, word_len = 0;
    for (int i = 0; i < words.size(); ++i) {
        if (isalpha(words[i]) || isdigit(words[i])) {
            word_len += 1;
        }
        else {
            if (word_len != 0) {
                string new_word = words.substr(begin_idx, word_len);
                AddWord(new_word);

            }
            begin_idx = i + 1;
            word_len = 0;
        }
    }
    if (word_len != 0) {
        string new_word = words.substr(begin_idx, word_len);
        AddWord(new_word);
    }
}

bool WordsCounter::Comparator(string first, string second) {
    return this->map_of_words[first] > this->map_of_words[second];
}

void WordsCounter::ReadFile() {
    ifstream file;
    file.open(this->input_file);

    string words;

    while (file) {
        getline(file, words);
        this->DivideString(words);
    }
    this->list_of_words.sort(bind(&WordsCounter::Comparator, this, placeholders::_1, placeholders::_2));
}

void WordsCounter::WriteFile() {
    ofstream file;
    file.open(this->output_file);
    file << "Word;Frequency;Frequency(%)" << endl;
    for (auto &word : this->list_of_words) {
        file << word << "; " << this->map_of_words[word] << "; " << this->map_of_words[word] / (double)this->words_count * 100 << endl;
    }
    file.close();
}