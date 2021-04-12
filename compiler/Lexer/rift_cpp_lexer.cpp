#include "rift_cpp_lexer.h"

Lexer::Lexer(string src)
{
    this->src = src;
}

LexToken Lexer::nextToken()
{
    cout << src << endl;
    return ::FUNC;
}
