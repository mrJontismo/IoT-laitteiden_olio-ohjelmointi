#include <iostream>
#include <string>
#include <memory>
#include "Apartment.hpp"

Apartment::Apartment(std::shared_ptr<House> house, int apartment_number, double size, int rent) : house(house), apartment_number(apartment_number), size(size), rent(rent) {}

bool Apartment::operator<(const Apartment& other) const
{
    return rent < other.rent;
}

void Apartment::print() const
{
    std::string address = "";

    if (house)
    {
        address = house->getAddress();
    }

    std::cout << "Address: " << address << " " << apartment_number << std::endl;
    std::cout << "Area: " << size << "m^2" << std::endl;
    std::cout << "Rent: " << rent << "€ per month" << std::endl;
}