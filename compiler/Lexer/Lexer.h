#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

enum LexTokenType {
    EOF_GOOD,
    ERROR,

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

    //Types
    //STRING_TYPE
};

class Lexer 
{
    //public: class LexToken : tuple<int,int,int,LexTokenType,string>{};
    private:
        //Atributes
        int index, line, col;
        string src;
        vector<tuple<int,int,int,LexTokenType,string>> srcTokens; //index, line, col, token type, string value
        static unordered_map<string, LexTokenType> unaryOpAndSingleSymbols;
        static unordered_map<string, LexTokenType> concatenatableSymbols;
        static unordered_map<string, LexTokenType> reservedKeywords;

        //Functions
        void createLexerTokens();
        bool isEnd();
        char advance();
        char peek();
        tuple<int,int,int,LexTokenType,string> nextToken();
        tuple<int,int,int,LexTokenType,string> readString(string lexValue);
        tuple<int,int,int,LexTokenType,string> readInteger(string lexValue);
        tuple<int,int,int,LexTokenType,string> readName(string lexValue);

    public:
        Lexer(string src);
        const vector<tuple<int,int,int,LexTokenType,string>> getSrcTokens();
        //const toString(); const toString(int); For error handling
};
