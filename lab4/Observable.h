#pragma once
#include <iostream>
#include <vector>
#include "Observer.h"

class Observable {
public:
    void AddObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void NotifyUpdate() {
        int size = observers.size();
        for (int i = 0; i < size; ++i) {
            observers[i]->Update();
        }
    }

private:
    std::vector<Observer*> observers;
};


