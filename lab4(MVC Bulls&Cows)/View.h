#pragma once
#include "Model.h"
#include <iostream>
#include "Observer.h"


class View : public Observer{
public:
    explicit View(Model* model) {
        this->model = model;
        this->model->AddObserver(this);
    }

    void Update() override {
        system("cls");
        std::cout << "Move | Number | Bulls | Cows" << std::endl;
        std::vector<info> history = model->GetHistory();
        for (auto &i : history) {
            std::cout << "  " << i.moves << "  |  ";
            for (int j = 0; j < 4; ++j) {
                std::cout << i.number[j];
            }
            std::cout << "  |   " << i.bulls << "   |  " << i.cows << std::endl;
        }
    }

    ~View() = default;

private:
    Model* model;
};

