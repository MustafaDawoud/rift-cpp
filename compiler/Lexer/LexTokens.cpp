#include "LexTokens.h"

LexToken::LexToken(int line, int col, string value)
{
    //Position p(line, col);
    //this->pos = p;
    //this->type =  //reservedWordsAndSymbols[value];
    //this->value = value;
}

LexTokenTypes LexToken::getLexTokenType() { return this->type; }

pair<int,int> LexToken::getPosition() { return this->pos; }
