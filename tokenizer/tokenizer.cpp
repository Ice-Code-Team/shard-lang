#include <iostream>
#include <string>
#include <vector>
#include <map>

// Type (enum) of all token types
typedef enum TokenTypes {
    // Single delims (DELIM) ----------------------------------------------------------------

    TT_PAREN_OPEN_DELIM,
    TT_PAREN_CLOSE_DELIM,
    TT_STR_DELIM,
    TT_CHR_DELIM,
    TT_INDEX_OPEN_DELIM,
    TT_INDEX_CLOSE_DELIM,
    TT_FUNCTION_OPEN_DELIM,
    TT_FUNCTION_CLOSE_DELIM,

    // Multiple chars delims (DELIM) ----------------------------------------------------------------

    TT_COMMENT_OPEN_DELIM,
    TT_COMMENT_CLOSE_DELIM,

    // Single char no-close (SYM) ----------------------------------------------------------------

    TT_PTR_SYM,
    TT_EOL_SYM,

    // Multiple chars types (TYP / WRD) ----------------------------------------------------------------
    
    TT_INT_TYP,
    TT_DOUBLE_TYP,
    TT_STR_TYP,
    TT_BOOL_TYP,
    TT_CHR_TYP,
    TT_CONST_TYP,

    // Single char symbols (SYM) ----------------------------------------------------------------

    TT_GREATER_SYM,
    TT_LESS_SYM,

    // Multiple chars symbols (SYM) ----------------------------------------------------------------

    TT_IS_EQUAL_SYM,
    TT_ASSIGN_SYM,
    TT_GREATER_OR_EQU_SYM,
    TT_LESS_OR_EQU_SYM,

    // Statements (STMT) ----------------------------------------------------------------

    TT_IF_STMT,
    TT_ELSEIF_STMT,
    TT_ELSE_STMT,
    TT_DO_STMT,
    TT_WHILE_STMT,
    TT_FOR_STMT,

    // Operators (OP) ----------------------------------------------------------------

    TT_PLUS_OP,
    TT_MINUS_OP,
    TT_TIMES_OP,
    TT_DIV_OP,

    // Digits
    TT_CHAR_DGT,
    TT_NUM_DGT
} TokenType;

// Type (enum) of all single char token types
typedef enum SingleCharTokenTypes {
    // Single delims (DELIM) ----------------------------------------------------------------

    STT_PAREN_OPEN_DELIM,
    STT_PAREN_CLOSE_DELIM,
    STT_STR_DELIM,
    STT_CHR_DELIM,
    STT_INDEX_OPEN_DELIM,
    STT_INDEX_CLOSE_DELIM,
    STT_FUNCTION_OPEN_DELIM,
    STT_FUNCTION_CLOSE_DELIM,

    // Single char no-close (SYM) ----------------------------------------------------------------

    STT_PTR_SYM,
    STT_EOL_SYM,

    // Single char symbols (SYM) ----------------------------------------------------------------

    STT_GREATER_SYM,
    STT_LESS_SYM,
    STT_FOR_STMT,

    // Operators (OP) ----------------------------------------------------------------

    STT_PLUS_OP,
    STT_MINUS_OP,
    STT_TIMES_OP,
    STT_DIV_OP
} SingleCharTokenType;

// Type (enum) of all multiple chars token types
typedef enum TokenTypes {
    // Multiple chars delims (DELIM) ----------------------------------------------------------------

    TT_COMMENT_OPEN_DELIM,
    TT_COMMENT_CLOSE_DELIM,

    // Multiple chars types (TYP / WRD) ----------------------------------------------------------------
    
    TT_INT_TYP,
    TT_DOUBLE_TYP,
    TT_STR_TYP,
    TT_BOOL_TYP,
    TT_CHR_TYP,
    TT_CONST_TYP,

    // Multiple chars symbols (SYM) ----------------------------------------------------------------

    TT_IS_EQUAL_SYM,
    TT_ASSIGN_SYM,
    TT_GREATER_OR_EQU_SYM,
    TT_LESS_OR_EQU_SYM,

    // Statements (STMT) ----------------------------------------------------------------

    TT_IF_STMT,
    TT_ELSEIF_STMT,
    TT_ELSE_STMT,
    TT_DO_STMT,
    TT_WHILE_STMT,
    TT_FOR_STMT,

    // Operators (OP) ----------------------------------------------------------------

    TT_PLUS_OP,
    TT_MINUS_OP,
    TT_TIMES_OP,
    TT_DIV_OP,

    // Digits
    TT_CHAR_DGT,
    TT_NUM_DGT
} TokenType;

// Content lists ----------------------------------------------------------------

// List of all tokens types (matches the enum content)
TokenType token_types_list[] = { 
  TT_PAREN_OPEN_DELIM, TT_PAREN_CLOSE_DELIM, TT_STR_DELIM, TT_CHR_DELIM, TT_INDEX_OPEN_DELIM, TT_INDEX_CLOSE_DELIM, TT_FUNCTION_OPEN_DELIM, TT_FUNCTION_CLOSE_DELIM, TT_COMMENT_OPEN_DELIM, TT_COMMENT_CLOSE_DELIM, 
  TT_PTR_SYM, TT_EOL_SYM, 
  TT_INT_TYP, TT_DOUBLE_TYP, TT_STR_TYP, TT_BOOL_TYP, TT_CHR_TYP, TT_CONST_TYP,
  TT_GREATER_SYM, TT_LESS_SYM, TT_IS_EQUAL_SYM, TT_ASSIGN_SYM, TT_GREATER_OR_EQU_SYM, TT_LESS_OR_EQU_SYM, 
  TT_IF_STMT, TT_ELSEIF_STMT, TT_ELSE_STMT, TT_DO_STMT, TT_WHILE_STMT, TT_FOR_STMT,
  TT_PLUS_OP, TT_MINUS_OP, TT_TIMES_OP, TT_DIV_OP,
  TT_CHAR_DGT, TT_NUM_DGT
};

// List of all tokens
std::string tokens_list[] = {
  "(", ")", "\"", "'", "[", "]", "{", "}", "/*", "*/",
  ".", ";",
  "int", "double", "str", "bool", "chr", "const", 
  ">", "<", "==", "<<", ">=", "<=", 
  "if", "elseif", "else", "do", "while", "for",
  "+", "-", "*", "/",
  "", ""
};

class Token {
    public:
        Token(std::string code) {
            std::vector line_chunks = split(code_to_tokenize, ';');

            code_to_tokenize = code;
            index = 0;
        }

        void setIndex(int value) {
            index = value;
        }

        int getIndex() {
            return index;
        }

        TokenType getType() {
            
        }

        char getValue() {
            
        }

    private:
        std::string code_to_tokenize;
        int index;
        TokenType type;
        char value;
};

// Token Combinations ----------------------------------------------------------------

// Math --------------------------------

class Add
{
    public:
        Add(std::string num1, std::string num2) {
            operato = '+';
            delimiter = ',';
        }
    private:
        char operato;
        char delimiter;
        int num1, dec1;
        int num2, dec2;

};

// Function prototypes ----------------------------------------------------------------

// Insert a single token at the end of token_match map
void InsertToken(TokenType token_type, std::string token);
// Insert all tokens at the end of token_match map using InsertToken() function
void InsertAllTokens();
// Prints all tokens in token_match map
void PrintTokens();
// Tokenize and go along the code
void TokenizeCode(std::string code);
// Splits a string into a vector of strings with a defined string delimiter
std::vector<std::string> split(std::string string_to_split, std::string delimiter);
// Splits a string into a vector of strings with a defined char delimiter
std::vector<std::string> split(std::string string_to_split, char delimiter);

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

void TokenizeCode(std::string code) {
    std::vector<TokenType> code_tokens;
}

// split with string
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
    std::string* final_string = &splitted_string[0];
    return splitted_string;
}

// split with char
std::vector<std::string> split(std::string string_to_split, char delimiter) {
    std::vector<std::string> splitted_string;
    int index = 0;
    for(int i = 0; i < string_to_split.length(); i++) {
        if(string_to_split[i] == delimiter) {
            index += 1;
            continue;
        }
        splitted_string[index] += string_to_split[i];
    }
    return splitted_string;
}
