#pragma once
#include "Exception.h"

class ParserError : public Exception {
public:
    ParserError(int line_number, int count) : Exception("Parser Error: line - " + std::to_string(line_number) + ", column - " + std::to_string(count)) {}
};


