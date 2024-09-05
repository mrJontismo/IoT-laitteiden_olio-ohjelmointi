#include <iostream>
#include <deque>

class RunningAverage
{
private:
    std::deque<int> values;
    size_t max_size;

public:
    RunningAverage(size_t max_size);
    void add_value(int value);
    double get_average() const;
};

RunningAverage::RunningAverage(size_t size) : max_size(size) {}

void RunningAverage::add_value(int value)
{
    if (values.size() >= max_size)
    {
        values.pop_back();
    }
    values.push_front(value);
}

double RunningAverage::get_average() const 
{
    double sum = 0.0;

    if (values.empty())
    {
        return sum;
    }

    for (auto value : values)
    {
        sum += static_cast<double>(value);
    }

    sum /= values.size();

    return sum;
}

int main()
{
    RunningAverage avg(5);
    int input = 0;

    std::cout << "Enter numbers (enter 0 to stop):" << std::endl;

    while (true)
    {
        std::cin >> input;
        if (input == 0) {
            break;
        }
        avg.add_value(input);
        std::cout << "Current running average: " << avg.get_average() << std::endl;
    }

    std::cout << "Final running average: " << avg.get_average() << std::endl;
    return 0;
}
