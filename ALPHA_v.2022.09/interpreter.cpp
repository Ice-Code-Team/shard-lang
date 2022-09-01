#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "interpreter.h"

// Single data struct
typedef struct memoryData {
    std::string type;
    std::string name;
    std::string value;
} memoryData;

// Vector with all datas
std::vector<memoryData> memory {
    { "str", "sys","Shard lang - ALPHA v.2022.09"}
};

std::string var_types[] = { "int", "double", "str", "char", "bool" };
std::string assign_operator = "<<";
char end_line = ';';

std::vector<std::string> string_split(std::string string_to_split, std::string delimiter);

void to_code_lines(std::vector<std::string> code) {
    for(int i = 0; i < code.size(); i++) {
        try {
            interpret(code[i]);
        } catch(...) {
            std::cout << "Error occured while getting code lines" << std::endl;
        }
    }
}

bool interpret(std::string code) {
    // Terms split
    std::vector<std::string> terms = string_split(code, " ");

    // Variable declaration
    for(int i = 0; i < var_types->size(); i++) {
        if(terms[0] == var_types[i]) {
            std::string type = var_types[i];
            std::string name = terms[1];

            // Case declaration
            if(terms[1].back() == end_line) {
                std::cout << "Case declaration";
            }
        }
    }
    return true;
}

// Split function

std::vector<std::string> string_split(std::string string_to_split, std::string delimiter) {
    std::vector<std::string> splitted_string;
    int index = 0;
    int delimiter_index = 0;
    while(true) {
        delimiter_index = string_to_split.find(delimiter, index);
        if(delimiter_index == std::string::npos) {
            splitted_string.push_back(string_to_split.substr(index, string_to_split.size() - index));
            break;
        } else {
            splitted_string.push_back(string_to_split.substr(index, delimiter_index - index));
            index = delimiter_index + delimiter.size();
        }
    }
    return splitted_string;
}