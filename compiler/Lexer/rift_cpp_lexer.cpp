#include "rift_cpp_lexer.h"

Lexer::Lexer(string src)
{
    this->src = src;
}

void Lexer::nextToken()
{
    cout << src << endl;
}
