#include "Dump.h"
#include "../Exception/InvalidNumberOfArguments.h"

static TemplateBlockMaker<Dump> maker("dump");

std::list<std::string> Dump::Execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
    if (args.size() != 1) {
        throw InvalidNumberOfArguments();
    }
    std::ofstream file(args[0]);
    if (file.is_open()) {
        for (auto &line : text) {
            file << line << std::endl;
        }
    }
    file.close();

    return text;
}

BlockType Dump::GetType() {
    return BlockType::INOUT;
}