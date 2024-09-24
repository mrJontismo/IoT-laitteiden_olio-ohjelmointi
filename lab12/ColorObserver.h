#pragma once

#include <iostream>
#include "Observer.h"

class ColorObserver : public Observer
{
public:
    void update(int new_value) override
    {
        std::cout << "Value changed to: " << new_value << std::endl;
    }
};