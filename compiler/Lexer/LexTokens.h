#include <utility>
#include <string>
#include <unordered_map>

using namespace std;

enum LexTokenTypes {
    //EOF Tokens
    EOF_GOOD,
    EOF_BAD,

    // KEYWORDS
    FUNC,
    STRUCT,
    SIG,
    IMPL,
    WITH,
    FIELD,
    METHOD,
    SELF,
    NEW,
    LET,
    IN,
    IF,
    THEN,
    ELSE,
    WHILE,
    RETURN,
    BREAK,
    CONTINUE,
    NIL,
    TRUE,
    FALSE,

    // SEPARATORS
    L_CURLY_BRACE,
    R_CURLY_BRACE,
    SEMI_COLON,
    COMMA,
    COLON,

    // OPERATORS
    L_BRACKET,
    R_BRACKET,
    L_BRACE,
    R_BRACE,
    DOT,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    NOT,
    LT,
    LQ,
    GT,
    GQ,
    EQ,
    NEQ,
    AND,
    OR,
    ASSIGN,
    ARROW,

    // LITERALS
    INT_LIT,
    STRING_LIT,
    ID
};

class LexToken
{
    private:
        pair<int,int> pos;
        LexTokenTypes type;
        string value;

        static const unordered_map<string, LexTokenTypes> reservedWordsAndSymbols;

    public:
        LexToken(int line, int col, string value);
        LexTokenTypes getLexTokenType();
        pair<int,int> getPosition();
};

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
     {"->", LexTokenTypes::ARROW}};
