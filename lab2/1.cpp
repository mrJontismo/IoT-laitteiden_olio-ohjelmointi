#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string input;

    while (true)
    {
        std::cout << "Enter a line with numbers or \"stop\": ";
        std::getline(std::cin, input);

        if (input.find("stop") == 0)
        {
            break;
        }
        
        int num = 0;
        int sum = 0;
        int count = 0;

        std::istringstream num_stream(input);

        while (num_stream >> num)
        {
            sum += num;
            ++count;
        }

        std::cout << "Total of " << count << " numbers is " << sum << "\n";
    }

    return 0;
}