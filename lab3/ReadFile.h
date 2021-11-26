#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "Block.h"
#include "TemplateBlockMaker.h"

class ReadFile : public Block {
public:

    std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) override {
        if (args.size() != 1) {
            throw std::exception();
        }

        std::list<std::string> new_text;
        std::fstream file;
        file.open(args[0]);
        while (file) {
            std::string temp;
            getline(file, temp);
            new_text.emplace_back(temp);
        }
        file.close();
        return new_text;
    }

    BlockType GetType() override {
        return BlockType::IN;
    }
};

static TemplateBlockMaker<ReadFile> maker("readfile");
