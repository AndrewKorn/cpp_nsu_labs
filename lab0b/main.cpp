#include <iostream>
#include "WordsCounter.h"
#include <string>

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cout << "Incorrect input" << std::endl;
        return 0;
    }

    std::string input_file = argv[1];
    std::string output_file = argv[2];

    WordsCounter words_counter(input_file, output_file);
    words_counter.ReadFile();
    words_counter.WriteFile();
    return 0;
}
