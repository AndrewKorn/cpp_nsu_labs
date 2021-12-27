#pragma once
#include <iostream>
#include <vector>
#include "Model.h"
#include <memory>

class Player {
public:
    virtual bool InputNumber(Model* model) = 0;

    virtual ~Player() = default;
};


