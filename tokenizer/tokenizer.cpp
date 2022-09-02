#include <iostream>
#include <string>
#include <vector>
#include <map>

// Type (enum) of all token types
typedef enum TokenTypes {
    // Single delims (DELIM) ----------------------------------------------------------------

    PAREN_DELIM_OPEN,
    PAREN_DELIM_CLOSE,
    STR_DELIM,
    INDEX_DELIM_OPEN,
    INDEX_DELIM_CLOSE,
    FUNCTION_DELIM_OPEN,
    FUNCTION_DELIM_CLOSE,

    // Multiple chars delims (DELIM) ----------------------------------------------------------------

    COMMENT_DELIM_OPEN,
    COMMENT_DELIM_CLOSE,

    // Single char no-close (SYM) ----------------------------------------------------------------

    PTR_SYM,
    EOL_SYM,

    // Multiple chars types (TYP / WRD) ----------------------------------------------------------------

    INT_TYP,
    DOUBLE_TYP,
    STR_TYP,
    BOOL_TYP,
    CHR_TYP,
    CONST_WRD,

    // Single char symbols (SYM) ----------------------------------------------------------------

    GREATER_SYM,
    LESS_SYM,

    // Multiple chars symbols (SYM) ----------------------------------------------------------------

    IS_EQUAL_SYM,
    ASSIGN_SYM,
    GREATER_OR_EQU_SYM,
    LESS_OR_EQU_SYM,

    // Statements (STMT) ----------------------------------------------------------------

    IF_STMT,
    ELSEIF_STMT,
    ELSE_STMT,
    DO_STMT,
    WHILE_STMT,
    FOR_STMT
} TokenType;

// Content lists ----------------------------------------------------------------

// List of all tokens types (matches the enum content)
TokenType token_types_list[] = { PAREN_DELIM_OPEN, PAREN_DELIM_CLOSE, STR_DELIM, INDEX_DELIM_OPEN, INDEX_DELIM_CLOSE, FUNCTION_DELIM_OPEN, FUNCTION_DELIM_CLOSE, COMMENT_DELIM_OPEN, COMMENT_DELIM_CLOSE, PTR_SYM, EOL_SYM, INT_TYP, DOUBLE_TYP, STR_TYP, BOOL_TYP, CHR_TYP, CONST_WRD, GREATER_SYM, LESS_SYM, IS_EQUAL_SYM, ASSIGN_SYM, GREATER_OR_EQU_SYM, LESS_OR_EQU_SYM, IF_STMT, ELSEIF_STMT, ELSE_STMT, DO_STMT, WHILE_STMT, FOR_STMT};

// List of all tokens
std::string tokens_list[] = {"(", ")", "\"", "[", "]", "{", "}", "/*", "*/", ".", ";", "int", "double", "str", "bool", "chr", "const", ">", "<", "==", "<<", ">=", "<=", "if", "elseif", "else", "do", "while", "for"};

// Function prototypes ----------------------------------------------------------------

// Insert a single token at the end of token_match map
void InsertToken(TokenType token_type, std::string token);
// Insert all tokens at the end of token_match map using InsertToken() function
void InsertAllTokens();
// Prints all tokens in token_match map
void PrintTokens();
// Splits a string into a vector of strings with a defined delimiter
std::vector<std::string> split(std::string string_to_split, std::string delimiter);

// Main variables declaration ----------------------------------------------------------------

// Map of matches between token types and tokens
std::map<TokenType, std::string> token_match;

// Main function ----------------------------------------------------------------

int main()
{
    InsertAllTokens();
    PrintTokens();
    return 0;
}
/*
    tokens = {
        "type": ...
        "value": ...
    }
*/

// Functions bodies ----------------------------------------------------------------

// InsertToken
void InsertToken(TokenType token_type, std::string token) {
    token_match.insert(std::pair<TokenType, std::string>(token_type, token));
}

// InsertAllTokens
void InsertAllTokens() {
    for(int i = 0; i < sizeof(token_types_list) / sizeof(token_types_list[0]); i++) {
        InsertToken(token_types_list[i], tokens_list[i]);
    }
}

// PrintTokens
void PrintTokens() {
    std::map<TokenType, std::string>::iterator itr;
    for(itr=token_match.begin();itr!=token_match.end();itr++)
    {
        std::cout<<itr->first<<" "<<itr->second<<std::endl;
    }
}

// split
std::vector<std::string> split(std::string string_to_split, std::string delimiter) {
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
