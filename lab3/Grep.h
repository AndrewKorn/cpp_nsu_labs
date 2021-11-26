#pragma once

#include <iostream>
#include <list>
#include <vector>
#include "Block.h"
#include "TemplateBlockMaker.h"


class Grep : public Block {
    std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) override {
        if (args.size() != 1) {
            throw std::exception();
        }
        std::list<std::string> new_text;
        for (auto &line : text) {
            for (int i = 0; i < line.size(); ++i) {
                if (line[i] == args[0][0]) {
                    if (line.substr(i, args[0].size()) == args[0]) {
                        new_text.emplace_back(line);
                        break;
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

static TemplateBlockMaker<Grep> maker("grep");

