#pragma once

#include <iostream>
#include <string>

class House {
private:
    std::string address;
    double size;
    int price;

public:
    House(const std::string& address = "", double size = 0.0, int price = 0);
    
    friend std::ostream& operator<<(std::ostream& os, const House& house);
    friend std::istream& operator>>(std::istream& is, House& house);
    bool operator<(const House& other) const;

    void setAddress(const std::string& address);
    void setArea(double size);
    void setPrice(int price);
    std::string getAddress() const;
};