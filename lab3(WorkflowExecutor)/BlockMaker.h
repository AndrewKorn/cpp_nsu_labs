#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Block.h"

class BlockMaker {
public:
    virtual Block* Create() = 0;
    virtual ~BlockMaker() = default;
};
