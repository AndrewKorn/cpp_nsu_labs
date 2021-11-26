#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "Block.h"
#include "TemplateBlockMaker.h"

class Dump : public Block {
    std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) override {
        if (args.size() != 1) {
            throw std::exception();
        }

        std::ofstream file(args[0], std::ios::app);
        if (file.is_open()) {
            for (auto &line : text) {
                file << line << std::endl;
            }
        }
        file.close();

        return text;
    }

    BlockType GetType() override {
        return BlockType::INOUT;
    }
};

static TemplateBlockMaker<Dump> maker("dump");