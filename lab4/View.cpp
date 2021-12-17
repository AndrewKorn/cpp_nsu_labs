#include "View.h"

void View::SyncWithModel(Model& model, std::vector<Info>& info, int player) {
    if (player == 1) {
        system("cls");
    }
    info.resize(info.size() + 1);
    info.back().moves = model.GetMoves();
    info.back().number = model.GetNumber();
    if (model.GetMode() == 'b') {
        info.back().bulls = model.GetBulls(info.back().number);
        info.back().cows = model.GetCows(info.back().number);
    }
    else if (model.GetMode() == 'p') {
        info.back().bulls = model.GetBulls();
        info.back().cows = model.GetCows();
    }
    if (player == 1) {
        ShowMessage("_______player1 history_______\n");
    }
    if (player == 2) {
        ShowMessage("_______player2 history_______\n");
    }
    std::cout << "Move | Number | Bulls | Cows" << std::endl;
    for (auto &i : info) {
        std::cout << "  " << i.moves << "  |  ";
        for (int j = 0; j < 4; ++j) {
            std::cout << i.number[j];
        }
        std::cout << "  |   " << i.bulls << "   |  " << i.cows << std::endl;
    }
}

void View::ShowMessage(const std::string& message) {
    std::cout << message;
}
