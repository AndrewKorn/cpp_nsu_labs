#pragma once
#include "Player.h"

class Bot : public Player {
public:
    bool InputNumber(Model* model) override {
        std::vector<char> number;
        number.resize(4);
        bool is_used[10];
        srand(time(NULL));
        for (bool & i : is_used) {
            i = false;
        }
        for (int i = 0; i < 4; ++i) {
            int idx = rand() % 10;
            if (!is_used[idx]) {
                number[i] = idx + 48;
                is_used[idx] = true;
            }
            else {
                --i;
            }
        }
        model->SetNumber(number);
        return true;
    }

    ~Bot() override = default;
};


