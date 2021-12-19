#pragma once
#include <memory>

#include "Model.h"
#include "View.h"
#include "Person.h"
#include "Bot.h"

enum class Mode {
    BOT,
    PERSON
};

class Controller {
public:
    explicit Controller(Model* model) {
        this->model = model;
    }

    Mode ChooseMode() {
        std::cout << "Choose mode(0 - bot, 1 - person): ";
        int mode;
        std::cin >> mode;
        if (mode == 0) {
            return Mode::BOT;
        }
        else if (mode == 1) {
            return Mode::PERSON;
        }
        else {
            std::cout << "Incorrect input, the bot is playing by default";
            return Mode::BOT;
        }
    }

    std::shared_ptr<Player> CreatePlayer() {
        auto mode = ChooseMode();
        if (mode == Mode::PERSON) {
            return std::shared_ptr<Player>(new Person);
        }
        else {
            return std::shared_ptr<Player>(new Bot);
        }
    }

    void StartNewGame() {
        system("cls");
        auto player = CreatePlayer();
        model->SetAnswer();
        while (!model->IsWin()) {
            std::cout << "attempt " << model->GetHistory().size() + 1 << ", ";
            std::cout << "Enter a number: ";
            if (player->InputNumber(model)) {
                continue;
            }
        }
        std::cout << "Wow you win!" << std::endl;
    }

    ~Controller() = default;

private:
    Model* model;
};