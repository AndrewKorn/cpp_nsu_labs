#include "Model.h"
#include <ctime>

bool Model::IsWin() {
    return bulls == 4;
}

int Model::GetBulls(std::vector<char> number) {
    bulls = 0;
    for (int i = 0; i < 4; ++i) {
        if (answer[i] == number[i]) {
            bulls += 1;
        }
    }
    return bulls;
}

int Model::GetCows(std::vector<char> number) {
    cows = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (answer[j] == number[i] && (i != j)) {
                cows += 1;
            }
        }
    }
    return cows;
}

bool Model::CheckNumber(std::vector<char> number) {
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

int Model::GetMoves() {
    return moves;
}

void Model::SetNumber(std::vector<char> number) {
    num = number;
}

void Model::SetAnswer() {
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
}

std::vector<char> Model::GetNumber() {
    return num;
}

void Model::SetMoves(int m) {
    moves = m;
}

void Model::SetBulls(int bull) {
    bulls = bull;
}

void Model::SetCows(int cow) {
    cows = cow;
}

void Model::SetMode(char m) {
    mode = m;
}

char Model::GetMode() {
    return mode;
}

int Model::GetBulls() {
    return bulls;
}

int Model::GetCows() {
    return cows;
}
