#include <iostream>
#include "CSVParser.h"
#include <string>
#include <fstream>

int main() {
    std::ifstream file("D://cpp/cpp_nsu_labs/lab5(CSVParser)/in.csv");
    CSVParser<int, std::string, int> parser(file, 0);
    try {
        for (std::tuple<int, std::string, int> tp : parser) {
            std::cout << tp << std::endl;
        }
    }
    catch (Exception& exception) {
        std::cout << exception.what();
    }
    return 0;
}
