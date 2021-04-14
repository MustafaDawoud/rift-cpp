#include "rift_cpp_lexer.h"


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
    return this->listOfTokens;
}

//************************************************************************************************
//Private
//************************************************************************************************

//Returns next token for iteration.
LexToken Lexer::nextToken()
{
    cout << src << endl;
    return LexToken(0,0,"");
}

//----------------------------
//Create list of tokens
//----------------------------
void Lexer::createLexerTokens()
{
    //Handle errors in here
    /*
    LexToken nextToken = lex.nextToken();
    LexTokenTypes tokenType = nextToken.getLexTokenType();

    vector<LexToken> tokenList;
    tokenList.push_back(nextToken);

    while(tokenType != LexTokenTypes::EOF_GOOD && tokenType != LexTokenTypes::EOF_BAD)
    {
        tokenList.push_back(nextToken);
        nextToken = lex.nextToken();
        tokenType = nextToken.getLexTokenType();
    }

    if(nextToken.getLexTokenType() == LexTokenTypes::EOF_BAD)
    {
        cout << "Something went wrong in lexer" << endl;
    }
    */
}

