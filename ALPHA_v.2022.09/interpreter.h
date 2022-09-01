#ifndef __INTERPRETER__H__
#define __INTERPRETER__H__

#include <iostream>
#include <string>
#include <vector>

void to_code_lines(std::vector<std::string> code);

bool interpret(std::string code);

#endif