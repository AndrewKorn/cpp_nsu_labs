#pragma once

#include <iostream>
#include <list>
#include <vector>
#include "Block.h"
#include "TemplateBlockMaker.h"

class Sort : public Block {
    TemplateBlockMaker<Sort> maker;

    std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) override {
        if (!args.empty()) {
            throw std::exception();
        }
        std::list<std::string> new_text = text;
        new_text.sort();
        return new_text;
    }

    BlockType GetType() override {
        return BlockType::INOUT;
    }
};

static TemplateBlockMaker<Sort> maker("sort");
