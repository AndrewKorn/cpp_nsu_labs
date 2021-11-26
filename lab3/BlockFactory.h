#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include "Block.h"
#include "BlockMaker.h"

class BlockFactory {
    BlockFactory() = default;
    std::map<std::string, BlockMaker*> _makers;

public:
    static BlockFactory& GetInstance() {
        static BlockFactory factory;
        return factory;
    }

    void RegisterMaker(const std::string &key, BlockMaker* maker) {
        if (_makers.find(key) != _makers.end()) {
            throw std::exception();
        }
        _makers[key] = maker;
    }

    Block* Create(std::string &block_name) {
        auto i = _makers.find(block_name);
        if (i == _makers.end()) {
            throw std::exception();
        }
        BlockMaker* maker = i->second;
        return maker->Create();
    }
};
