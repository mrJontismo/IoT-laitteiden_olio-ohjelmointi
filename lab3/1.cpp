#include <iostream>
#include <map>

void print(const std::map<std::string, int> &names)
{
    for (auto it = names.begin(); it != names.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << std::endl;
    }
}

int main()
{
    std::map<std::string, int> names;

    while (true)
    {        
        std::cout << "Enter name or \"stop\" or \"print\": ";
        std::string name;
        std::getline(std::cin, name);

        if (name == "stop")
        {
            break;
        }
        else if (name == "print")
        {
            print(names);
        }
        else
        {
            int value = 0;
            std::cout << "Enter integer: ";
            std::cin >> value;
            std::cin.ignore();
            names[name] = value;
        }
    }

    return 0;
}