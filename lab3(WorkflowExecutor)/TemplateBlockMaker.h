#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "BlockMaker.h"
#include "BlockFactory.h"

template<typename T>
class TemplateBlockMaker : public BlockMaker {
public:
    Block* Create() override {
        return new T();
    }

    TemplateBlockMaker(const std::string& block_name) {
        BlockFactory::GetInstance().RegisterMaker(block_name, this);
    }
};
