#pragma once
#include <exception>
#include <string>


class InvalidNumberOfArguments : public std::exception {
public:
    InvalidNumberOfArguments() = default;
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message = "invalid number of arguments";
};


