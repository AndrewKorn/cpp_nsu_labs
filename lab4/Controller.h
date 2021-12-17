#pragma once
#include "Model.h"
#include "View.h"

class Controller {
public:
    void StartNewGame(Model& model, View& view);
    void SelectMode(Model& model, View& view);
    bool InputNumber(Model& model, View& view);
    void InputBullsAndCows(Model& model, View& view);
    ~Controller() = default;
};