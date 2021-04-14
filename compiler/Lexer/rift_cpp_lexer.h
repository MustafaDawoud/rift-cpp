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
        LexToken nextToken();
        void createLexerTokens();

    public:
        Lexer(string src);
        vector<LexToken> getListOfTokens();

};
