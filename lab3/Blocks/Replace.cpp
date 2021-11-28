#include "Replace.h"
#include "../Exception/InvalidNumberOfArguments.h"


static TemplateBlockMaker<Replace> maker("replace");

std::list<std::string> Replace::Execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
    if (args.size() != 2) {
        throw InvalidNumberOfArguments();
    }
    std::list<std::string> new_text = text;
    for (auto &line : new_text) {
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == args[0][0]) {
                if (line.substr(i, args[0].size()) == args[0]) {
                    line.replace(i, args[0].size(), args[1]);
                }
            }
        }
    }
    return new_text;
}

BlockType Replace::GetType() {
    return BlockType::INOUT;
}