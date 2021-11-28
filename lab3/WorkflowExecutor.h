#pragma once

#include <iostream>
#include <list>
#include <vector>
#include "WorkflowParser.h"
#include "BlockFactory.h"
#include "TemplateBlockMaker.h"
#include "Block.h"
#include "Exception/WrongBlockType.h"

class WorkflowExecutor {
public:

    void CheckBlocks(std::list<std::pair<Block*, std::vector<std::string>>> block_objects) {
        if (block_objects.front().first->GetType() != BlockType::IN || block_objects.back().first->GetType() != BlockType::OUT) {
            throw WrongBlockType();
        }
        for (auto block_object : block_objects) {
            if ((block_object != block_objects.front()) && (block_object != block_objects.back())) {
                if (block_object.first->GetType() != BlockType::INOUT) {
                    throw WrongBlockType();
                }
            }
        }
    }

    void ExecuteWorkflow(std::istream &in) {
        WorkflowParser parser;
        auto blocks = parser.GetBlocks(in);

        std::list<std::pair<Block*, std::vector<std::string>>> block_objects;
        for (auto block : blocks) {
            Block *block_object = BlockFactory::GetInstance().Create(block.first);
            block_objects.emplace_back(block_object, block.second);
        }

        CheckBlocks(block_objects);

        std::list<std::string> text;
        for (auto block_object : block_objects) {
            text = block_object.first->Execute(text, block_object.second);
        }
    }

    ~WorkflowExecutor() = default;
};

