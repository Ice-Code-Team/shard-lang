#include <iostream>
#include <string>
#include <vector>

#include "interpreter.h"

const std::string end = "end();";

std::vector<std::string> get_code();

int main()
{
    std::cout << "Enter the code to by compiled : " << std::endl;

    std::vector<std::string> lines = get_code();
    std::string line = "";

    to_code_lines(lines);

    return 0;
}

std::vector<std::string> get_code() {
    std::vector<std::string> lines = {};
    std::string line;
    while(true) {
        std::cout << "> shr > ";
        std::getline(std::cin,line);
        if(line == end)
            break;
        else
            lines.push_back(line);
    }

    return lines;
}