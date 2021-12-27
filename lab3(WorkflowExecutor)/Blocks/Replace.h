#pragma once
#include <iostream>
#include <list>
#include <vector>
#include "../Block.h"
#include "../TemplateBlockMaker.h"

class Replace : public Block {
    std::list<std::string> Execute(const std::list<std::string> &text, const std::vector<std::string> &args) override;
    BlockType GetType() override;
    ~Replace() override = default;
};
