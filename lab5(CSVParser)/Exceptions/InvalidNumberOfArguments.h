#pragma once
#include "Exception.h"

class InvalidNumberOfArguments : public Exception {
public:
    InvalidNumberOfArguments(int line_number, int count) : Exception("Invalid number of arguments: line - " + std::to_string(line_number) + ", arguments - " + std::to_string(count)) {}
};


