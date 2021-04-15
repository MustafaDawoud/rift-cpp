#include "rift_cpp_lexer.h"

using namespace std;

//Public

//Constructor
//Params: string src - input source file
//Description - Initializes list of tokens
Lexer::Lexer(string src)
{
    this->src = src;
    createLexerTokens();
}

//Return listOfTokens
vector<LexToken> Lexer::getListOfTokens()
{
    return listOfTokens;
}

//************************************************************************************************
//Private
//************************************************************************************************

//Returns next token for iteration.
LexToken Lexer::nextToken(int line, int col)
{
    
    for(int i = 0; i < src.length(); i++)
    {
        line += 1; col += 1;
        cout << src[i] << endl;
    }

    return LexToken(line,col,"func");
}

//----------------------------
//Create list of tokens
//----------------------------
void Lexer::createLexerTokens()
{
    LexToken next = nextToken(0,0);
    listOfTokens.push_back(next);
    
    while(next.getType() != LexTokenTypes::EOF_GOOD && next.getType() != LexTokenTypes::EOF_BAD)
    {
        cout << "ROW AND COLUMN!!!!!!!!!!!!!!!!!" << next.getLine() << ", " << next.getColumn() << endl; break;
        next = nextToken(next.getLine(), next.getColumn());
        listOfTokens.push_back(next);
    }

    //Handle errors in here
    if(next.getType() == LexTokenTypes::EOF_BAD)
    {
        cout << "Something went wrong in lexer" << endl;
    }

}

