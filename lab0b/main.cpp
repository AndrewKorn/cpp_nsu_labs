#include <iostream>
#include "WordsCounter.h"
#include <string>
using namespace std;

int main(int argc, char** argv) {
    if (argc != 3) {
        cout << "Incorrect input" << endl;
        return 0;
    }
    string input_file = argv[1];
    string output_file = argv[2];

    WordsCounter words_counter(input_file, output_file);
    words_counter.ReadFile();
    words_counter.WriteFile();
    return 0;
}
