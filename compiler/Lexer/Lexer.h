#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

enum LexTokenType {
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

class Lexer 
{
    //public: class LexToken : tuple<int,int,int,LexTokenType,string>{};
    private:
        //Atributes
        int index, line, col;
        string src;
        vector<tuple<int,int,int,LexTokenType,string>> srcTokens; //index, line, col, token type, string value
        static unordered_map<string, LexTokenType> reservedWordsAndSymbols;

        //Functions
        tuple<int,int,int,LexTokenType,string> nextToken();
        void createLexerTokens();
        bool isEnd();
        char advance();

    public:
        Lexer(string src);
        const vector<tuple<int,int,int,LexTokenType,string>> getSrcTokens();
        //const toString(); const toString(int); For error handling
};
