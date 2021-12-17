#pragma once
#include <vector>
#include <iostream>

struct Info {
    int moves;
    std::vector<char> number;
    int bulls;
    int cows;
};

class Model {
public:
    bool IsWin();
    void SetNumber(std::vector<char> number);
    void SetAnswer();
    void SetMoves(int move);
    void SetBulls(int bull);
    void SetCows(int cow);
    void SetMode(char m);
    bool CheckNumber(std::vector<char> number);
    std::vector<char> GetNumber();
    char GetMode();
    int GetBulls(std::vector<char> number);
    int GetBulls();
    int GetCows(std::vector<char> number);
    int GetCows();
    int GetMoves();
    ~Model() = default;

private:
    char mode;
    std::vector<char> answer;
    std::vector<char> num;
    int bulls;
    int cows;
    int moves;
};


