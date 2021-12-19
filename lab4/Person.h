#pragma once
#include "Player.h"


class Person : public Player {
public:
    bool InputNumber(Model* model) override {
        std::vector<char> number;
        number.resize(4);
        for (int i = 0; i < 4; ++i) {
            std::cin >> number[i];
        }
        std::cin.sync();
        if (!model->CheckNumber(number)) {
            std::cout << "Wrong input, all digits must be different. Pls try again" << std::endl;
            return false;
        }
        else {
            model->SetNumber(number);
            return true;
        }
    }

    ~Person() override = default;
};


