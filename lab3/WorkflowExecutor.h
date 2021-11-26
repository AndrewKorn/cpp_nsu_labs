#pragma once

#include <iostream>
#include <list>
#include <vector>
#include "WorkflowParser.h"
#include "BlockFactory.h"
#include "TemplateBlockMaker.h"
#include "Block.h"

class WorkflowExecutor {
public:

    void ExecuteWorkflow(std::istream &in) {
        /*BlockFactory::GetInstance().RegisterMaker("readfile", new TemplateBlockMaker<ReadFile>());
        BlockFactory::GetInstance().RegisterMaker("writefile", new TemplateBlockMaker<WriteFile>());
        BlockFactory::GetInstance().RegisterMaker("sort", new TemplateBlockMaker<Sort>());
        BlockFactory::GetInstance().RegisterMaker("replace", new TemplateBlockMaker<Replace>());
        BlockFactory::GetInstance().RegisterMaker("grep", new TemplateBlockMaker<Grep>());
        BlockFactory::GetInstance().RegisterMaker("dump", new TemplateBlockMaker<Dump>());*/

        WorkflowParser parser;
        auto blocks = parser.GetBlocks(in);

        std::list<std::pair<Block*, std::vector<std::string>>> block_objects;
        for (auto block : blocks) {
            Block *block_object = BlockFactory::GetInstance().Create(block.first);
            block_objects.emplace_back(block_object, block.second);
        }

        //check blocks
        if (block_objects.front().first->GetType() != BlockType::IN || block_objects.back().first->GetType() != BlockType::OUT) {
            throw std::exception();
        }
        for (auto block_object : block_objects) {
            if ((block_object != block_objects.front()) && (block_object != block_objects.back())) {
                if (block_object.first->GetType() != BlockType::INOUT) {
                    throw std::exception();
                }
            }
        }

        std::list<std::string> text;
        for (auto block_object : block_objects) {
            try {
                text = block_object.first->Execute(text, block_object.second);
            } catch (std::exception &ex) {
                std::cerr <<  "Error: " << ex.what() << std::endl;
            }
        }
    }
};

