#pragma once
#include <exception>
#include <string>

class MultipleMakers : public std::exception {
public:
    MultipleMakers() = default;
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message = "multiple makers";
};


