#include <iostream>
#include <string>
#include <vector>

#include "interpreter.h"

std::vector<std::string> get_code() {
    do {
        std::cout << "> ";
        std::cin >> line;
        if(line == end)
            break;
        else
            lines.push_back(line);
    } while(line != end);
}

int main()
{
    const std::string end = "end()";
    std::cout << "Enter the code to by compiled : " << std::endl;

    std::vector<std::string> lines = {};
    std::string line = "";

    interpret(lines);

    return 0;
}
