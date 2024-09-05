#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "House.hpp"

House::House(const std::string& address, double size, int price) : address(address), size(size), price(price) {}

std::ostream& operator<<(std::ostream& os, const House& house)
{
    char delim = ',';
    os << house.address << delim << house.size << delim << house.price;
    return os;
}

std::istream& operator>>(std::istream& is, House& house)
{
    std::string line;
    char delim = ',';

    if (std::getline(is, line))
    {
        std::stringstream ss(line);
        std::getline(ss, house.address, delim);
        ss >> house.size;
        ss.ignore(1, delim);
        ss >> house.price;
    }

    return is;
}


bool House::operator<(const House& other) const
{
    if (size == 0 || other.size == 0)
    {
        return false;
    }

    double price_per_m2 = static_cast<double>(price) / size;
    double other_price_per_m2 = static_cast<double>(other.price) / other.size;

    return price_per_m2 < other_price_per_m2;
}

void House::setAddress(const std::string& address)
{
    this->address = address;
}

void House::setArea(double size)
{
    this->size = size;
}

void House::setPrice(int price)
{
    this->price = price;
}

std::string House::getAddress() const
{
    return address;
}