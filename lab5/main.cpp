#include <iostream>
#include "CSVParser.h"
#include <string>
#include <fstream>

int main() {
    std::ifstream file("D://cpp/cpp_nsu_labs/lab5/in.csv");
    CSVParser<int, std::string, float> parser(file, 0);
    for (std::tuple<int, std::string, float> tp : parser) {
        std::cout << tp << std::endl;
    }
    return 0;
}
