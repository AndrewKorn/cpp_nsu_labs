#include "Grep.h"
#include "../Exception/InvalidNumberOfArguments.h"

static TemplateBlockMaker<Grep> maker("grep");

std::list<std::string> Grep::Execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
    if (args.size() != 1) {
        throw InvalidNumberOfArguments();
    }
    std::list<std::string> new_text;
    for (auto &line : text) {
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == args[0][0]) {
                if (line.substr(i, args[0].size()) == args[0]) {
                    new_text.emplace_back(line);
                    break;
                }
            }
        }
    }
    return new_text;
}

BlockType Grep::GetType() {
    return BlockType::INOUT;
}