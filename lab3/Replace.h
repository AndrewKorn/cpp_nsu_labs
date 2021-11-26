#pragma once

#include <iostream>
#include <list>
#include <vector>
#include "Block.h"

class Replace : public Block {
    std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) override {
        if (args.size() != 2) {
            throw std::exception();
        }
        std::list<std::string> new_text = text;
        for (auto &line : new_text) {
            for (int i = 0; i < line.size(); ++i) {
                if (line[i] == args[0][0]) {
                    if (line.substr(i, args[0].size()) == args[0]) {
                        line.replace(i, args[0].size(), args[1]);
                    }
                }
            }
        }
        return new_text;
    }

    BlockType GetType() override {
        return BlockType::INOUT;
    }
};
