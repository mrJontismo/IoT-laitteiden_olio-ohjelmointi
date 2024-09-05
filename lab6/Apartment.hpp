#pragma once

#include <memory>
#include "House.hpp"

class Apartment
{
private:
    std::shared_ptr<House> house;
    int apartment_number;
    double size;
    int rent;

public:
    Apartment(std::shared_ptr<House> house = nullptr, int apartment_number = 0, double size = 0.0, int rent = 0.0);
    bool operator<(const Apartment& other) const;
    void print() const;
};