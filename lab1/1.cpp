#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers;
    int num = 0;

    std::cout << "How many numbers do you want to enter? ";
    std::cin >> num;

    for (int i = 0; i < num; ++i)
    {
        int number = 0;
        std::cout << "Enter nr[" << i + 1 << "]: ";
        std::cin >> number;
        numbers.push_back(number);
    }

    std::cout << "You entered: ";
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        std::cout << numbers[i];
        if (i < numbers.size() - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}