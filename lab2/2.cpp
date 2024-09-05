#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>

int main()
{
    std::vector<std::string> names;
    std::string input;

    std::cout << "Enter directory names or a blank line to stop entry: \n";
    while (true)
    {
        std::getline(std::cin, input);
        if(input.empty())
        {
            break;
        }
        names.push_back(input);
    }

    std::filesystem::path relative_path;
    for (const std::string &str : names)
    {
        relative_path /= str;
    }

    std::filesystem::create_directories(relative_path);

    std::filesystem::path file_path = relative_path / "result.txt";
    std::filesystem::path absolute_path = std::filesystem::absolute(file_path);

    std::ofstream results;
    results.open(file_path);

    std::cout << absolute_path << "\n";
    results << absolute_path << "\n";

    for (const std::string &str : names)
    {
        std::cout << str << "\n";
        results << str << "\n";
    }

    std::cout << relative_path << "\n";
    results << relative_path << "\n";

    return 0;
}