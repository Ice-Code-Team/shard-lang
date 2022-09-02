#include <iostream>
#include <string>
#include <vector>
#include <map>

std::vector<std::string> string_split(std::string string_to_split, std::string delimiter);

std::map<TokenType, std::string[]> tokenizer;

typedef enum TokenTypes {
    // Single delims
    PAREN_DELIM_OPEN,
    PAREN_DELIM_CLOSE,
    STR_DELIM,
    INDEX_DELIM_OPEN,
    INDEX_DELIM_CLOSE,
    FUNCTION_DELIM_OPEN,
    FUNCTION_DELIM_CLOSE,
    // Multiple chars delims
    COMMENT_DELIM_OPEN,
    COMMENT_DELIM_CLOSE,
    // Single char no-close
    POINTER,
    EOL,
    // Multiple chars types
    TYPE_WRD,
    CONST_WRD,
    // Single char symbols
    GREATER_SYM,
    LESS_SYM,
    // Multiple chars symbols
    ASSIGN_SYM,
    GREATER_OR_EQU_SYM,
    LESS_OR_EQU_SYM,
    // Statements
    IF_STMT,
    ELSEIF_STMT,
    ELSE_STMT,
    WHILE_STMT,
    FOR_STMT
} TokenType;

int main()
{
    tokenizer.insert(std::pair<TokenType, std::string[]>(PAREN_DELIM_OPEN, { "(" }));
}
/*
    tokens = {
        "type": ...
        "value": ...
    }
*/

// Split function
std::vector<std::string> string_split(std::string string_to_split, std::string delimiter) {
    std::vector<std::string> splitted_string;
    int index = 0;
    int delimiter_index = 0;
    while (true) {
        delimiter_index = string_to_split.find(delimiter, index);
        if (delimiter_index == std::string::npos) {
            splitted_string.push_back(string_to_split.substr(index, string_to_split.size() - index));
            break;
        }
        else {
            splitted_string.push_back(string_to_split.substr(index, delimiter_index - index));
            index = delimiter_index + delimiter.size();
        }
    }
    return splitted_string;
}
