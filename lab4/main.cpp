#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "House.hpp"

int main()
{
    std::vector<House> houses;

    std::string address;
    std::cout << "Enter address for house 1: ";
    std::getline(std::cin, address);

    double size = 0.0;
    std::cout << "Enter size (area) for house 1: ";
    std::cin >> size;
    std::cin.ignore();

    int price = 0;
    std::cout << "Enter price for house 1: ";
    std::cin >> price;
    std::cin.ignore();

    House house(address, size, price);
    houses.push_back(house);

    std::cout << "Enter address for house 2: ";
    std::getline(std::cin, address);

    std::cout << "Enter size (area) for house 2: ";
    std::cin >> size;
    std::cin.ignore();

    std::cout << "Enter price for house 2: ";
    std::cin >> price;
    std::cin.ignore();

    House house1;
    house1.setAddress(address);
    house1.setArea(size);
    house1.setPrice(price);

    houses.push_back(house1);

    std::cout << "Enter house 3 address, area and price (separated by commas): ";
    House house2;
    std::cin >> house2;

    houses.push_back(house2);

    std::cout << "Enter house 4 address, area and price (separated by commas): ";
    House house3;
    std::cin >> house3;

    houses.push_back(house3);

    std::cout << "Enter house 5 address, area and price (separated by commas): ";
    House house4;
    std::cin >> house4;

    houses.push_back(house4);

    std::sort(houses.begin(), houses.end());

    for (const auto& house : houses)
    {
        std::cout << house << std::endl;
    }

    return 0;
}
