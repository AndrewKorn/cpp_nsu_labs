#pragma once
#include <exception>
#include <string>

class UnrecognizedBlock : public std::exception {
public:
    UnrecognizedBlock() = default;
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message = "unrecognized block";
};

