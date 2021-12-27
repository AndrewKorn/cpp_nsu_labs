#pragma once
#include <utility>
#include <vector>
#include <iostream>
#include "Observable.h"
#include <ctime>

struct info {
    std::vector<char> number;
    int bulls = 0;
    int cows = 0;
    int moves = 0;
};

class Model : public Observable {
public:
    Model() {
        history.resize(0);
    }

    bool IsWin() {
        if (!history.empty()) {
            return (history.back().bulls == 4);
        }
        else {
            return false;
        }
    };

    void SetAnswer() {
        std::vector<char> ans;
        ans.resize(4);
        bool is_used[10];
        srand(time(nullptr));
        for (bool & i : is_used) {
            i = false;
        }
        for (int i = 0; i < 4; ++i) {
            int idx = rand() % 10;
            if (!is_used[idx]) {
                ans[i] = idx + 48;
                is_used[idx] = true;
            }
            else {
                --i;
            }
        }
        answer = ans;
    };

    int GetBulls(std::vector<char>& number) {
        int bulls = 0;
        for (int i = 0; i < 4; ++i) {
            if (answer[i] == number[i]) {
                bulls += 1;
            }
        }
        return bulls;
    }

    int GetCows(std::vector<char>& number) {
        int cows = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (answer[j] == number[i] && (i != j)) {
                    cows += 1;
                }
            }
        }
        return cows;
    }

    void SetNumber(std::vector<char>& number) {
        int bulls = GetBulls(number);
        int cows = GetCows(number);
        info new_info;
        new_info.number = number;
        new_info.bulls = bulls;
        new_info.cows = cows;
        if (history.empty()) {
            new_info.moves = 1;
        }
        else {
            new_info.moves = history.back().moves + 1;
        }
        history.emplace_back(new_info);
        NotifyUpdate();
    }

    std::vector<info> GetHistory() {
        return history;
    }

    bool CheckNumber(std::vector<char>& number) {
        if (number.size() != 4) {
            return false;
        }
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                if (number[i] == number[j]) {
                    return false;
                }
            }
        }
        return true;
    }

    ~Model() = default;

private:
    std::vector<char> answer;
    std::vector<info> history;
};


