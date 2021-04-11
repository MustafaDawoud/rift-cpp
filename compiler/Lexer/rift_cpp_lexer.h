#include <iostream>
#include <unordered_map>
#include "TokenType.h"

using namespace std;

class Lexer 
{
    private:
        string src;
        unordered_map<string, string> reservedWords;

    public:
        Lexer(string src);
        void nextToken();
};
