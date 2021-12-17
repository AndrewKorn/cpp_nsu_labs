#include "Model.h"
#include "View.h"
#include "Controller.h"

int main() {
    Model model;
    View view;
    Controller controller;
    controller.StartNewGame(model, view);
    return 0;
}
