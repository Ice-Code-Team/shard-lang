#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <variant>

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
    MTT_FOR_STMT
};

// List of all variable value token types
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
// Prints all tokens in token_match map of a specific type
void PrintTokens(std::string token_class);
// Tokenize and go along the code
void TokenizeCode(std::string code);
// Splits a string into a vector of strings with a defined string delimiter
std::vector<std::string> split(std::string string_to_split, std::string delimiter);
// Splits a string into a vector of strings with a defined char delimiter
std::vector<std::string> split(std::string string_to_split, char delimiter);
// Checks if a substring is in a string
bool in(std::string substring_to_check, std::string string_to_check_in);
// Checks if a char is in a string
bool in(char char_to_check, std::string string_to_check_in);
// Removes a given string from a vector of strings
std::vector<std::string> RemoveValue(std::vector<std::string> vector_to_remove_from, std::string value_to_remove);

// Token class (for iteration) ----------------------------------------------------------------
class Token {
    public:
        Token(std::string code) {
            code_to_tokenize = split(code, ' ');
            index = 0;
        }

        void run() {
            for(int i = 0; i < code_to_tokenize.size(); i++) {
                std::string tokenizing = code_to_tokenize[i];
                if(tokenizing.size() == 1) {
                    int temp = all_tokens.size();
                    get_singlechar_token(tokenizing[0]);
                    if(all_tokens.size() == temp) {
                        get_variablevalue_token(tokenizing[0]);
                    }
                }
                else {
                    int temp = all_tokens.size();
                    get_multiplechars_token();
                    if(all_tokens.size() == temp) {
                        for(int j = 0; j < code_to_tokenize[i].size(); j++) {
                            get_singlechar_token(tokenizing[j]);
                        }
                    }
                    else {
                        std::cout << "General failure" << std::endl;
                        i++;
                    }
                }
            }
        }

        void get_singlechar_token(char tok) {
            for(int i = 0; i < sizeof(singleCharTokenTypes_list); i++) {
                if(tok == singleCharTokens_values_list[i][0]) {
                    all_tokens.insert(all_tokens.end(), singleCharTokenTypes_list[i]);
                }
            }
        }

        void get_multiplechars_token() {
            for(int i = 0; i < sizeof(multipleCharsTokenTypes_list); i++) {
                if(code_to_tokenize[index] == multipleCharsTokens_values_list[i]) {
                    all_tokens.insert(all_tokens.end(), multipleCharsTokenTypes_list[i]);
                }
            }
        }

        void get_variablevalue_token(char tok) {
            for(int i = 0; i < sizeof(variableValueTokenTypes_list); i++) {
                if(in(tok, variableValueTokens_values_list[i])) {
                    all_tokens.insert(all_tokens.end(), variableValueTokenTypes_list[i]);
                }
            }
        }

        void print_tokens() {
            for(int i = 0; i < all_tokens.size(); i++) {
                try {
                    std::cout << std::get<SingleCharTokenType>(all_tokens[i]);
                }
                catch(...) {
                    try {
                        std::cout << std::get<MultipleCharsTokenType>(all_tokens[i]);
                    }
                    catch(...) {
                        try {
                            std::cout << std::get<VariableValueTokenType>(all_tokens[i]);
                        }
                        catch(const std::bad_variant_access& e) {
                            std::cout << "Error: Token type not found" << std::endl;
                            std::cout << e.what() << std::endl;
                        }
                    }
                }
            }
        }

    private:
        // The code to tokenize
        std::vector<std::string> code_to_tokenize;
        // The index of the code actually being tokenized
        int index;
        // The vector of all tokens found
        std::vector<std::variant<SingleCharTokenType, MultipleCharsTokenType, VariableValueTokenType>> all_tokens;
};

// Main variables declaration ----------------------------------------------------------------

// Map of matches between token types and tokens (single char)
std::map<SingleCharTokenType, std::string> single_char_token_match;
// Map of matches between token types and tokens (multiple chars)
std::map<MultipleCharsTokenType, std::string> multiple_chars_token_match;
// Map of matches between token types and tokens (variable value)
std::map<VariableValueTokenType, std::string> variable_value_token_match;

// Main function ----------------------------------------------------------------

int main()
{
    InsertAllTokens();
    // PrintTokens();
    std::cout << "Tokenizing code..." << std::endl;
    TokenizeCode("int a << 5");
    std::cout << "Tokenizing code finished" << std::endl;
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
    std::map<VariableValueTokenType, std::string>::iterator ktr;
    std::cout << "Variable value tokens:" << std::endl;
    for(ktr=variable_value_token_match.begin();ktr!=variable_value_token_match.end();ktr++)
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
        std::map<MultipleCharsTokenType, std::string>::iterator itr;
        for(itr=multiple_chars_token_match.begin();itr!=multiple_chars_token_match.end();itr++)
        {
            std::cout<<itr->first<<" "<<itr->second<<std::endl;
        }
    }
    else if(token_class == "variable_value") {
        std::map<VariableValueTokenType, std::string>::iterator itr;
        for(itr=variable_value_token_match.begin();itr!=variable_value_token_match.end();itr++)
        {
            std::cout<<itr->first<<" "<<itr->second<<std::endl;
        }
    }
}

void TokenizeCode(std::string code) {
    std::cout << "Tokenizing code: " << code << std::endl;
    std::vector line_chunks = split(code, ';');
    
    for(int i = 0; i < line_chunks.size(); i++) {
        std::cout << "Tokenizing line: \"" << line_chunks[i] << "\"" << std::endl;
        Token tkn = Token(line_chunks[i]);
        tkn.run();
        tkn.print_tokens();
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
    std::string temp = "";
    for(int i = 0; i < string_to_split.length(); i++) {
        if(string_to_split[i] == delimiter) {
            splitted_string.push_back(temp);
            std::cout << "Added : " << temp << std::endl;
            temp = "";
        } else {
            temp += string_to_split[i];
        }
    }
    splitted_string.push_back(temp);
    while(splitted_string[splitted_string.size() - 1] == "") {
        splitted_string.pop_back();
    }
    splitted_string = RemoveValue(splitted_string, std::string(1, delimiter));
    return splitted_string;
}

// in (string)
bool in(std::string substring_to_check, std::string string_to_check_in) {
    return string_to_check_in.find(substring_to_check) != std::string::npos;
}

// in (char)
bool in(char char_to_check, std::string string_to_check_in) {
    return string_to_check_in.find(char_to_check) != std::string::npos;
}

// RemoveValue
std::vector<std::string> RemoveValue(std::vector<std::string> vector_to_remove_from, std::string value_to_remove) {
    std::vector<std::string> vector_removed;
    for(int i = 0; i < vector_to_remove_from.size(); i++) {
        if(vector_to_remove_from[i] != value_to_remove && vector_to_remove_from[i] != "") {
            vector_removed.push_back(vector_to_remove_from[i]);
        }
    }
    return vector_removed;
}
