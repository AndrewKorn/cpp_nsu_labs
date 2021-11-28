#include "ReadFile.h"

static TemplateBlockMaker<ReadFile> maker("readfile");

std::list<std::string> ReadFile::Execute(const std::list<std::string> &text, const std::vector<std::string> &args) {
    if (args.size() != 1) {
        throw std::exception();
    }

    std::list<std::string> new_text;
    std::fstream file;
    file.open(args[0]);
    while (file) {
        std::string temp;
        getline(file, temp);
        new_text.emplace_back(temp);
    }
    file.close();
    return new_text;
}

BlockType ReadFile::GetType() {
    return BlockType::IN;
}