#include <iostream>
#include <string>
#include <vector>
#include <map>

// Types (enums) of all token types

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
typedef enum MultipleCharsTokenTypes {
    // Multiple chars delims (DELIM) ----------------------------------------------------------------

    MTT_COMMENT_OPEN_DELIM,
    MTT_COMMENT_CLOSE_DELIM,

    // Multiple chars types (TYP / WRD) ----------------------------------------------------------------
    
    MTT_INT_TYP,
    MTT_DOUBLE_TYP,
    MTT_STR_TYP,
    MTT_BOOL_TYP,
    MTT_CHR_TYP,
    MTT_CONST_TYP,

    // Multiple chars symbols (SYM) ----------------------------------------------------------------

    MTT_IS_EQUAL_SYM,
    MTT_ASSIGN_SYM,
    MTT_GREATER_OR_EQU_SYM,
    MTT_LESS_OR_EQU_SYM,

    // Statements (STMT) ----------------------------------------------------------------

    MTT_IF_STMT,
    MTT_ELSEIF_STMT,
    MTT_ELSE_STMT,
    MTT_DO_STMT,
    MTT_WHILE_STMT,
    MTT_FOR_STMT,

    // Operators (OP) ----------------------------------------------------------------

    MTT_PLUS_OP,
    MTT_MINUS_OP,
    MTT_TIMES_OP,
    MTT_DIV_OP
} MultipleCharsTokenType;

// Type (enum) of all variable value token types
typedef enum VariableValueTokenTypes {
    VTT_CHAR,
    VTT_NUM
} VariableValueTokenType;

// Token type lists ----------------------------------------------------------------

// List of all single char token types
SingleCharTokenType singleCharTokenTypes_list[] = {
    STT_PAREN_OPEN_DELIM,
    STT_PAREN_CLOSE_DELIM,
    STT_STR_DELIM,
    STT_CHR_DELIM,
    STT_INDEX_OPEN_DELIM,
    STT_INDEX_CLOSE_DELIM,
    STT_FUNCTION_OPEN_DELIM,
    STT_FUNCTION_CLOSE_DELIM,

    STT_PTR_SYM,
    STT_EOL_SYM,

    STT_GREATER_SYM,
    STT_LESS_SYM,
    STT_FOR_STMT,

    STT_PLUS_OP,
    STT_MINUS_OP,
    STT_TIMES_OP,
    STT_DIV_OP
};

// List of all multiple chars token types
MultipleCharsTokenType multipleCharsTokenTypes_list[] = {
    MTT_COMMENT_OPEN_DELIM,
    MTT_COMMENT_CLOSE_DELIM,

    MTT_INT_TYP,
    MTT_DOUBLE_TYP,
    MTT_STR_TYP,
    MTT_BOOL_TYP,
    MTT_CHR_TYP,
    MTT_CONST_TYP,

    MTT_IS_EQUAL_SYM,
    MTT_ASSIGN_SYM,
    MTT_GREATER_OR_EQU_SYM,
    MTT_LESS_OR_EQU_SYM,

    MTT_IF_STMT,
    MTT_ELSEIF_STMT,
    MTT_ELSE_STMT,
    MTT_DO_STMT,
    MTT_WHILE_STMT,
    MTT_FOR_STMT,

    MTT_PLUS_OP,
    MTT_MINUS_OP,
    MTT_TIMES_OP,
    MTT_DIV_OP
};

VariableValueTokenType variableValueTokenTypes_list[] = {
    VTT_CHAR,
    VTT_NUM
};

// Token lists ----------------------------------------------------------------

std::string singleCharTokens_values_list[] = {
  "(", ")", "\"", "'", "[", "]", "{", "}", ".", ";", ">", "<", "+", "-", "*", "/"
};

std::string multipleCharsTokens_values_list[] = {
  "/*", "*/", "int", "double", "str", "bool", "chr", "const", "==", "<<", ">=", "<=", "if", "elseif", "else", "do", "while", "for"
};

std::string variableValueTokens_values_list[] = {
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIKJLMNOPQRSTUVWXYZ_", "0123456789"
};

// Token class (iterator) ----------------------------------------------------------------
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
void InsertToken(SingleCharTokenType token_type, std::string token);
// Insert a single token at the end of token_match map
void InsertToken(MultipleCharsTokenType token_type, std::string token);
// Insert a single token at the end of token_match map
void InsertToken(VariableValueTokenType token_type, std::string token);
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
std::map<SingleCharTokenType, std::string> single_char_token_match;
// Map of matches between token types and tokens
std::map<MultipleCharsTokenType, std::string> multiple_chars_token_match;
// Map of matches between token types and tokens
std::map<VariableValueTokenType, std::string> variable_value_token_match;

// Main function ----------------------------------------------------------------

int main()
{
    InsertAllTokens();
    PrintTokens();
    return 0;
}

// Functions bodies ----------------------------------------------------------------

// InsertToken
void InsertToken(SingleCharTokenType token_type, std::string token) {
    single_char_token_match.insert(std::pair<SingleCharTokenType, std::string>(token_type, token));
}
void InsertToken(MultipleCharsTokenType token_type, std::string token) {
    multiple_chars_token_match.insert(std::pair<MultipleCharsTokenType, std::string>(token_type, token));
}
void InsertToken(VariableValueTokenType token_type, std::string token) {
    variable_value_token_match.insert(std::pair<VariableValueTokenType, std::string>(token_type, token));
}

// InsertAllTokens
void InsertAllTokens() {
    for(int i = 0; i < sizeof(singleCharTokenTypes_list) / sizeof(singleCharTokenTypes_list[0]); i++) {
        InsertToken(singleCharTokenTypes_list[i], singleCharTokens_values_list[i]);
    }
    for(int i = 0; i < sizeof(multipleCharsTokenTypes_list) / sizeof(multipleCharsTokenTypes_list[0]); i++) {
        InsertToken(multipleCharsTokenTypes_list[i], multipleCharsTokens_values_list[i]);
    }
    for(int i = 0; i < sizeof(variableValueTokenTypes_list) / sizeof(variableValueTokenTypes_list[0]); i++) {
        InsertToken(variableValueTokenTypes_list[i], variableValueTokens_values_list[i]);
    }
}

// PrintTokens
void PrintTokens() {
    std::map<SingleCharTokenType, std::string>::iterator itr;
    std::cout << "Single char tokens:" << std::endl;
    for(itr=single_char_token_match.begin();itr!=single_char_token_match.end();itr++)
    {
        std::cout<<itr->first<<" "<<itr->second<<std::endl;
    }
    std::map<MultipleCharsTokenType, std::string>::iterator jtr;
    std::cout << "Multiple chars tokens:" << std::endl;
    for(jtr=multiple_chars_token_match.begin();jtr!=multiple_chars_token_match.end();jtr++)
    {
        std::cout<<jtr->first<<" "<<jtr->second<<std::endl;
    }
    std::map<SingleCharTokenType, std::string>::iterator ktr;
    std::cout << "Variable value tokens:" << std::endl;
    for(ktr=single_char_token_match.begin();ktr!=single_char_token_match.end();ktr++)
    {
        std::cout<<ktr->first<<" "<<ktr->second<<std::endl;
    }
}
void PrintTokens(std::string token_class) {
    if(token_class == "single_char") {
        std::map<SingleCharTokenType, std::string>::iterator itr;
        for(itr=single_char_token_match.begin();itr!=single_char_token_match.end();itr++)
        {
            std::cout<<itr->first<<" "<<itr->second<<std::endl;
        }
    }
    else if(token_class == "multiple_chars") {
        std::map<MultipleCharsTokenType, std::string>::iterator jtr;
        for(jtr=multiple_chars_token_match.begin();jtr!=multiple_chars_token_match.end();itr++)
        {
            std::cout<<jtr->first<<" "<<itr->second<<std::endl;
        }
    }
    else if(token_class == "variable_value") {
        std::map<SingleCharTokenType, std::string>::iterator itr;
        for(itr=single_char_token_match.begin();itr!=single_char_token_match.end();itr++)
        {
            std::cout<<itr->first<<" "<<itr->second<<std::endl;
        }
    }
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
