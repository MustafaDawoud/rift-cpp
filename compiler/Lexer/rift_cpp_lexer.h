#include <iostream>
#include <unordered_map>
#include "TokenTypes.h"

using namespace std;

class Lexer 
{
    private:
        string src;
        static unordered_map<string, LexToken> reservedWords;

    public:
        Lexer(string src);
        LexToken nextToken();
};
