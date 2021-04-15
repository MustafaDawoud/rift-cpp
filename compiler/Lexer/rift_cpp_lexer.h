#include <iostream>
#include <vector>
#include "LexTokens.h"

using namespace std;

class Lexer 
{
    private:
        //Atributes
        string src;
        vector<LexToken> listOfTokens;

        //Functions
        LexToken nextToken(int, int);
        void createLexerTokens();

    public:
        Lexer(string src);
        vector<LexToken> getListOfTokens();

};
