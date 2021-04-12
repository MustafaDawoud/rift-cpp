#include "rift_cpp_lexer.h"

Lexer::Lexer(string src)
{
    this->src = src;
}

Token Lexer::nextToken()
{
    cout << src << endl;
    return NULL;
}
