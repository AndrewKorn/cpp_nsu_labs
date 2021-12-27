#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <string>

class WorkflowParser {
public:
    std::list<std::pair<std::string, std::vector<std::string>>> GetBlocks(std::istream &in) {
        std::list<std::pair<std::string, std::vector<std::string>>> parsed;
        std::string text;
        std::vector<std::pair<std::string, std::vector<std::string>>> arr;
        while (in) {
            getline(in, text);
            if (text == "csed") {
                break;
            }
            if (isdigit(text[0])) {
                int num = 0;
                int i = 0;
                while (isdigit(text[i])) {
                    num = num * 10 + text[i] - 48;
                    i++;
                }
                while (!isalpha(text[i])) {
                    i++;
                }
                int idx = i;
                while (isalpha(text[i])) {
                    i++;
                }
                if (num + 1 > arr.size()) {
                    arr.resize(num + 1);
                }
                arr[num].first = text.substr(idx, i - idx);
                if (i != text.size()) {
                    i++;
                    idx = i;
                    while (i < text.size()) {
                        if (text[i] == ' ') {
                            arr[num].second.emplace_back(text.substr(idx, i - idx));
                            idx = i + 1;
                        }
                        i++;
                    }
                    arr[num].second.emplace_back(text.substr(idx, i - idx));
                }
            }
        }
        getline(in, text);
        int i = 0;
        int num = 0;
        while (i < text.size()) {
            while (isdigit(text[i])) {
                num = num * 10 + text[i] - 48;
                i++;
            }
            parsed.emplace_back(arr[num]);
            num = 0;
            if (i < text.size()) {
                while (!isdigit(text[i])) {
                    i++;
                }
            }
        }
        return parsed;
    }

    ~WorkflowParser() = default;
};
