#include "rift_cpp_lexer.h"

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

//Character advance

//Returns next token for iteration.
tuple<int,int,int,LexTokenType,string> Lexer::nextToken(int line, int col)
{

    return make_tuple(index, line, col, reservedWordsAndSymbols["func"], "func");//LexToken(index,line,col,"func");
}

//----------------------------
//Create list of tokens
//----------------------------
void Lexer::createLexerTokens()
{
    tuple<int,int,int,LexTokenType,string> next = nextToken(0,0);
    srcTokens.push_back(next);
    
    while(get<3>(next) != LexTokenType::EOF_GOOD && get<3>(next) != LexTokenType::EOF_BAD)
    {
        next = nextToken(get<1>(next), get<2>(next));
        srcTokens.push_back(next);
    }

    //Handle errors in here
    if(get<3>(next) == LexTokenType::EOF_BAD)
    {
        cout << "Something went wrong in lexer" << endl;
    }

}

