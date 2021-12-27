#pragma once

#include <iostream>
#include <list>
#include <vector>

enum class BlockType {
    IN,
    OUT,
    INOUT
};

class Block {
public:
    virtual std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) = 0;
    virtual BlockType GetType() = 0;
    virtual ~Block() = default;
};
