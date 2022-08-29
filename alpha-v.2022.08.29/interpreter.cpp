#include <iostream>
#include <string>
#include <vector>

#include "interpreter.h"

bool interpret(std::vector<std::string> code) {
    try {
        for(int i = 0; i < code.size(); i++) {
            std::cout << code[i] << std::endl;
        }
        return true;
    }
    catch(...) {
        return false;
    }
}
