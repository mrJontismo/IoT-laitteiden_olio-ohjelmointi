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

int main()
{
    srand(time(NULL));
    char choice;

    do {
        RandGen_2 lotto_gen(1, 40);
        std::vector<int> lotto(7);
        std::generate(lotto.begin(), lotto.end(), lotto_gen);
        std::cout << "Lotto: ";
        std::copy(lotto.begin(), lotto.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        RandGen_2 viking_gen(1, 48);
        std::vector<int> viking(6);
        std::generate(viking.begin(), viking.end(), viking_gen);
        std::cout << "Viking lotto: ";
        std::copy(viking.begin(), viking.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::sort(lotto.begin(), lotto.end());
        std::sort(viking.begin(), viking.end());

        std::vector<int> intersection_lv;
        std::set_intersection(lotto.begin(), lotto.end(), viking.begin(), viking.end(), std::back_inserter(intersection_lv));

        std::cout << "Matching numbers: ";
        PrintWithIndex printWithIndex_lv;
        std::for_each(intersection_lv.begin(), intersection_lv.end(), printWithIndex_lv);
        std::cout << std::endl;

        RandGen_2 eurojackpot_gen(1, 50);
        std::vector<int> eurojackpot(5);
        std::generate(eurojackpot.begin(), eurojackpot.end(), eurojackpot_gen);
        std::cout << "Eurojackpot: ";
        std::copy(eurojackpot.begin(), eurojackpot.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        std::sort(eurojackpot.begin(), eurojackpot.end());

        std::vector<int> intersection_all;
        std::set_intersection(intersection_lv.begin(), intersection_lv.end(), eurojackpot.begin(), eurojackpot.end(), std::back_inserter(intersection_all));

        std::cout << "Matching numbers in three sets: ";
        PrintWithIndex printWithIndex_all;
        std::for_each(intersection_all.begin(), intersection_all.end(), printWithIndex_all);
        std::cout << std::endl;

        std::cout << "Do you want to generate new numbers? (y/n): ";
        std::cin >> choice;
    } while  (choice == 'y');

    return 0;
}