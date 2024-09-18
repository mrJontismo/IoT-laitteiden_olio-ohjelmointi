#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

class RandGen_2
{
public:
    RandGen_2(int min_, int max_);
    int operator()();

private:
    int min;
    int max;
    std::vector<int> used_numbers;
};

RandGen_2::RandGen_2(int min_, int max_) : min(min_), max(max_) {}

int RandGen_2::operator()()
{
    if (used_numbers.size() >= static_cast<size_t>(max - min + 1))
    {
        throw std::runtime_error("Unable to produce unique random number");
    }

    int num = 0;
    do {
        num = min + rand() % (max - min + 1);
    } while (std::find(used_numbers.begin(), used_numbers.end(), num) != used_numbers.end());
    used_numbers.push_back(num);
    return num;
}

class PrintWithIndex
{
public:
    PrintWithIndex();
    void operator()(int number);

private:
    int index;
};

PrintWithIndex::PrintWithIndex() : index(1) {}

void PrintWithIndex::operator()(int number)
{
    std::cout << "#" << index++ << ": " << number << " ";
}

void test_generator(RandGen_2& ur, int count)
{
    std::vector<int> numbers;
    std::cout << "Generating numbers:" << std::endl;
    try
    {
        for (int i = 0; i < count; ++i)
        {
            int num = ur();
            numbers.push_back(num);
        }
    }
    catch (std::runtime_error& e)
    {
        std::cout << "Exception: " << e.what()
                  << ". Tried to generate " << count << " random numbers. Got only " << numbers.size() << std::endl;
    }

    for (int num : numbers)
    {
        std::cout << num << std::endl;
    }
    std::cout << "End of generator" << std::endl;
}

int main()
{
    srand(time(NULL));

    RandGen_2 randGen(5, 13);
    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13); // this will cause exception

    RandGen_2 randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70); // this will cause exception

    return 0;
    return 0;
}