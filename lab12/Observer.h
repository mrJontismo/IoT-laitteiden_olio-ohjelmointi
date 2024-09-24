#pragma once

class Observer
{
public:
    virtual void update(int new_value) = 0;
    virtual ~Observer() = default;
};