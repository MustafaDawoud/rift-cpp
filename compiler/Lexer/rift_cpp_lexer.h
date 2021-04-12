#include <iostream>
#include "LexTokens.h"

using namespace std;

class Lexer 
{
    private:
        string src;

    public:
        Lexer(string src);
        LexToken nextToken();
};
