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

