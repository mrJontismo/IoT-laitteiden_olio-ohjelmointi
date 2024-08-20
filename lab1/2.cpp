#include <iostream>
#include <string>

void replace_char(std::string &str, char original, char target)
{
    for (char &c : str)
    {
        if (c == original)
        {
            c = target;
        }
    }
}

int main()
{
    std::string input;
    std::string replace;

    while (true)
    {
        std::cout << "Enter a string: ";
        std::getline(std::cin, input);

        std::cout << "Enter character to replace or “stop”: ";
        std::getline(std::cin, replace);
        
        if (replace == "stop")
        {
            break;
        }

        replace_char(input, replace[0], '_');

        std::cout << "Result: " << input << std::endl;
    }

    return 0;
}
