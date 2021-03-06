#pragma once
#include <exception>
#include <string>

class Exception : public std::exception {
public:
    explicit Exception() = default;
    explicit Exception(const std::string& message) : message(message) {}

    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message;
};



