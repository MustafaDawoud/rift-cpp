#include "LexTokens.h"

const unordered_map<string, LexTokenTypes> LexToken::reservedWordsAndSymbols = 
     // EOF TOKENS
     {{"EOF_GOOD", LexTokenTypes::EOF_GOOD},
     {"EOF_BAD", LexTokenTypes::EOF_BAD},
     
     // KEYWORDS
     {"func", LexTokenTypes::FUNC},
     {"struct", LexTokenTypes::STRUCT},
     {"sig", LexTokenTypes::SIG},
     {"impl", LexTokenTypes::IMPL},
     {"with", LexTokenTypes::WITH},
     {"field", LexTokenTypes::FIELD},
     {"method", LexTokenTypes::METHOD},
     {"self", LexTokenTypes::SELF},
     {"new", LexTokenTypes::NEW},
     {"let", LexTokenTypes::LET},
     {"in", LexTokenTypes::IN},
     {"if", LexTokenTypes::IF},
     {"then", LexTokenTypes::THEN},
     {"else", LexTokenTypes::ELSE},
     {"while", LexTokenTypes::WHILE},
     {"return", LexTokenTypes::RETURN},
     {"break", LexTokenTypes::BREAK},
     {"continue", LexTokenTypes::CONTINUE},
     {"nil", LexTokenTypes::NIL},
     {"true", LexTokenTypes::TRUE},
     {"false", LexTokenTypes::FALSE},

     // SEPARATORS
     {"{", LexTokenTypes::L_CURLY_BRACE},
     {"}", LexTokenTypes::R_CURLY_BRACE},
     {";", LexTokenTypes::SEMI_COLON},
     {",", LexTokenTypes::COMMA},
     {":", LexTokenTypes::COLON},

     // OPERATORS
     {"[", LexTokenTypes::L_BRACKET},
     {"]", LexTokenTypes::R_BRACKET},
     {"(", LexTokenTypes::L_BRACE},
     {")", LexTokenTypes::R_BRACE},
     {".", LexTokenTypes::DOT},
     {"+", LexTokenTypes::ADD},
     {"-", LexTokenTypes::SUB},
     {"*", LexTokenTypes::MUL},
     {"/", LexTokenTypes::DIV},
     {"%", LexTokenTypes::MOD},
     {"!", LexTokenTypes::NOT},
     {"<", LexTokenTypes::LT},
     {"<=", LexTokenTypes::LQ},
     {">", LexTokenTypes::GT},
     {">=", LexTokenTypes::GQ},
     {"==", LexTokenTypes::EQ},
     {"!=", LexTokenTypes::NEQ},
     {"&&", LexTokenTypes::AND},
     {"||", LexTokenTypes::OR},
     {"=", LexTokenTypes::ASSIGN},
     {"->", LexTokenTypes::ARROW}
};

LexToken::LexToken(int line, int col, string value)
{
    this->line = line;
    this->col = col;
    this->value = value;
    type =  reservedWordsAndSymbols[value];
}

int LexToken::getLine() { return line; }
int LexToken::getColumn() { return col; }
string LexToken::getValue() { return value; }
LexTokenTypes LexToken::getType() { return type; }

//pair<int,int> LexToken::getPosition() { return pos; }
