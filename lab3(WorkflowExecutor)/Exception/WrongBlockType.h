#pragma once
#include <exception>
#include <string>

class WrongBlockType : public std::exception {
public:
    WrongBlockType() = default;
    const char* what() const noexcept override {
        return message.c_str();
    }

private:
    std::string message = "wrong block type";
};


