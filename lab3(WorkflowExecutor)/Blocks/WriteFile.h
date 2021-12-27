#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include "../Block.h"
#include "../TemplateBlockMaker.h"

class WriteFile : public Block {
    std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) override;
    BlockType GetType() override;
    ~WriteFile() override = default;
};