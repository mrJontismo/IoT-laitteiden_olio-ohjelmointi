#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "House.hpp"
#include "Apartment.hpp"

int main()
{
    std::shared_ptr<House> kerrostalo = std::make_shared<House>("Testitie 123", 10000.0, 123000);
    std::shared_ptr<House> rivitalo = std::make_shared<House>("Kokeilukatu 345", 20000.0, 456000);

    std::vector<Apartment> apartments;

    Apartment kerrostalo_asunto1(kerrostalo, 101, 50.0, 1000);
    Apartment kerrostalo_asunto2(kerrostalo, 102, 70.0, 2000);
    Apartment kerrostalo_asunto3(kerrostalo, 103, 98.0, 3000);

    apartments.push_back(kerrostalo_asunto1);
    apartments.push_back(kerrostalo_asunto2);
    apartments.push_back(kerrostalo_asunto3);

    Apartment rivitalo_asunto1(rivitalo, 11, 100.0, 800);
    Apartment rivitalo_asunto2(rivitalo, 12, 150.0, 543);
    Apartment rivitalo_asunto3(rivitalo, 13, 200.0, 267);
    Apartment rivitalo_asunto4(rivitalo, 14, 300.0, 422);

    apartments.push_back(rivitalo_asunto1);
    apartments.push_back(rivitalo_asunto2);
    apartments.push_back(rivitalo_asunto3);
    apartments.push_back(rivitalo_asunto4);

    std::sort(apartments.begin(), apartments.end());

    for (const auto& apartment : apartments)
    {
        std::cout << "-----" << std::endl;
        apartment.print();
    }

    return 0;
}