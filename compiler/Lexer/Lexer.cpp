#include "Lexer.h"

using namespace std;

//************************************************************************************************
//Public
//************************************************************************************************

//Constructor
//Params: string src - input source file
//Description - Initializes list of tokens
Lexer::Lexer(string src)
{
    this->src = src;
    index = 0;
    createLexerTokens();
}

//Return listOfTokens
const vector<tuple<int,int,int,LexTokenType,string>> Lexer::getSrcTokens()
{
    return srcTokens;
}

//************************************************************************************************
//Private
//************************************************************************************************

unordered_map<string, LexTokenType> Lexer::reservedWordsAndSymbols = 
     // EOF TOKENS
     {{"EOF_GOOD", LexTokenType::EOF_GOOD},
     {"EOF_BAD", LexTokenType::EOF_BAD},
     
     // KEYWORDS
     {"func", LexTokenType::FUNC},
     {"struct", LexTokenType::STRUCT},
     {"sig", LexTokenType::SIG},
     {"impl", LexTokenType::IMPL},
     {"with", LexTokenType::WITH},
     {"field", LexTokenType::FIELD},
     {"method", LexTokenType::METHOD},
     {"self", LexTokenType::SELF},
     {"new", LexTokenType::NEW},
     {"let", LexTokenType::LET},
     {"in", LexTokenType::IN},
     {"if", LexTokenType::IF},
     {"then", LexTokenType::THEN},
     {"else", LexTokenType::ELSE},
     {"while", LexTokenType::WHILE},
     {"return", LexTokenType::RETURN},
     {"break", LexTokenType::BREAK},
     {"continue", LexTokenType::CONTINUE},
     {"nil", LexTokenType::NIL},
     {"true", LexTokenType::TRUE},
     {"false", LexTokenType::FALSE},

     // SEPARATORS
     {"{", LexTokenType::L_CURLY_BRACE},
     {"}", LexTokenType::R_CURLY_BRACE},
     {";", LexTokenType::SEMI_COLON},
     {",", LexTokenType::COMMA},
     {":", LexTokenType::COLON},

     // OPERATORS
     {"[", LexTokenType::L_BRACKET},
     {"]", LexTokenType::R_BRACKET},
     {"(", LexTokenType::L_BRACE},
     {")", LexTokenType::R_BRACE},
     {".", LexTokenType::DOT},
     {"+", LexTokenType::ADD},
     {"-", LexTokenType::SUB},
     {"*", LexTokenType::MUL},
     {"/", LexTokenType::DIV},
     {"%", LexTokenType::MOD},
     {"!", LexTokenType::NOT},
     {"<", LexTokenType::LT},
     {"<=", LexTokenType::LQ},
     {">", LexTokenType::GT},
     {">=", LexTokenType::GQ},
     {"==", LexTokenType::EQ},
     {"!=", LexTokenType::NEQ},
     {"&&", LexTokenType::AND},
     {"||", LexTokenType::OR},
     {"=", LexTokenType::ASSIGN},
     {"->", LexTokenType::ARROW}
};

bool Lexer::isEnd() { return index >= src.length(); }

//Character advance
char Lexer::advance()
{
    if(isEnd())
    {
        return '\0';
    }

    char c = src[index++];

    while(true)
    {
        if(isEnd())
        {
            return '\0';
        }
        if(c == '\n')
        {
            line++; col = 1;
        } 
        else if(c == ' ' || c == '\t')
        {
            col++;
        }
        else
        {
            col++;
            break;
        }
    }
    return c;
}

//Returns next token for iteration.
tuple<int,int,int,LexTokenType,string> Lexer::nextToken()
{
    char c = advance();
    string lexValue = "hola";
    
    while(true)
    {
        /*switch(c)
        {
            case '\n':
            case ' ':
        }*/
        break;
    }
    return make_tuple(index, line, col, reservedWordsAndSymbols["func"], lexValue);
}

//----------------------------
//Create list of tokens
//----------------------------
void Lexer::createLexerTokens()
{
    tuple<int,int,int,LexTokenType,string> next = nextToken();
    srcTokens.push_back(next);
    
    while(get<3>(next) != LexTokenType::EOF_GOOD && get<3>(next) != LexTokenType::EOF_BAD)
    {
        next = nextToken();
        srcTokens.push_back(next);
        cout << get<4>(next) << endl;
        break;
    }

    //Handle errors in here
    if(get<3>(next) == LexTokenType::EOF_BAD)
    {
        cout << "Something went wrong in lexer" << endl;
    }

}

