#pragma once
#include "Model.h"
#include <iostream>


class View {
public:
    void SyncWithModel(Model& model, std::vector<Info>& info, int player);
    void ShowMessage(const std::string& message);
    ~View() = default;
};

