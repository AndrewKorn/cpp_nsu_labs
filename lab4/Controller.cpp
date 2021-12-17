#include "Controller.h"

void Controller::StartNewGame(Model& model, View& view) {
    system("cls");
    SelectMode(model, view);
    if (model.GetMode() == 'b') {
        std::vector<Info> info;
        model.SetAnswer();
        model.SetMoves(0);
        while (!model.IsWin()) {
            std::cout << "attempt " << model.GetMoves() + 1 << ", ";
            view.ShowMessage("enter a number: ");
            if (!InputNumber(model, view)) {
                continue;
            }
            model.SetMoves(model.GetMoves() + 1);
            view.SyncWithModel(model, info, 1);
        }
        view.ShowMessage("Wow you win!");
    }
    else if (model.GetMode() == 'p') {
        std::vector<Info> info1;
        std::vector<Info> info2;
        model.SetMoves(0);
        while (!model.IsWin()) {
            view.ShowMessage("player1, enter a number ");
            if (!InputNumber(model, view)) {
                continue;
            }
            model.SetMoves(model.GetMoves() + 1);
            view.ShowMessage("player2, how many bulls and cows in this number? ");
            InputBullsAndCows(model, view);
            if (model.IsWin()) {
                view.ShowMessage("Wow, player1 you win!");
                break;
            }
            view.SyncWithModel(model, info1, 1);
            view.ShowMessage("player2, enter a number ");
            if (!InputNumber(model, view)) {
                continue;
            }
            view.ShowMessage("player1, how many bulls and cows in this number? ");
            InputBullsAndCows(model, view);
            if (model.IsWin()) {
                view.ShowMessage("Wow, player2 you win!");
                break;
            }
            view.SyncWithModel(model, info2, 2);
        }
    }
}

bool Controller::InputNumber(Model& model, View& view) {
    std::vector<char> number;
    number.clear();
    number.resize(4);
    for (int i = 0; i < 4; ++i) {
        std::cin >> number[i];
    }
    if (!model.CheckNumber(number)) {
        view.ShowMessage("Wrong input, all digits must be different. Pls try again\n");
        return false;
    } else {
        model.SetNumber(number);
        return true;
    }
}

void Controller::SelectMode(Model &model, View &view) {
    char mode;
    view.ShowMessage("Select mode: p - vs player, b - vs bot ");
    std::cin >> mode;
    model.SetMode(mode);
}

void Controller::InputBullsAndCows(Model &model, View &view) {
    int bulls, cows;
    view.ShowMessage("\nhow many bulls: ");
    std::cin >> bulls;
    model.SetBulls(bulls);
    view.ShowMessage("how many cows: ");
    std::cin >> cows;
    model.SetCows(cows);
}