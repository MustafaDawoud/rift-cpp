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

unordered_map<string, LexTokenType> Lexer::reservedKeywords = 
     {{"func", LexTokenType::FUNC},
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
     {"false", LexTokenType::FALSE}
};

unordered_map<string, LexTokenType> Lexer::reservedUnaryOpAndSingleSymbols = 
     // EOF TOKENS
     {{"\0", LexTokenType::EOF_GOOD},
     
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
     {"*", LexTokenType::MUL},
     {"/", LexTokenType::DIV},
     {"%", LexTokenType::MOD},
     {"!", LexTokenType::NOT}
};

unordered_map<string, LexTokenType> Lexer::concatenatableSymbols = 
     {{"<", LexTokenType::LT},
     {"<=", LexTokenType::LQ},

     {">", LexTokenType::GT},
     {">=", LexTokenType::GQ},

     {"&&", LexTokenType::AND},
     {"||", LexTokenType::OR},

     {"==", LexTokenType::EQ},
     {"!=", LexTokenType::NEQ},
     {"=", LexTokenType::ASSIGN},

     {"-", LexTokenType::SUB},
     {"->", LexTokenType::ARROW}
};

bool Lexer::isEnd() { return index >= src.length(); }

char Lexer::peek()
{
    if(isEnd())
    {
        return '\0';
    }
    else
    {
        return src[index];
    }
}

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

tuple<int,int,int,LexTokenType,string> Lexer::readString()
{

    return make_tuple(index, line, col, LexTokenType::ERROR, "Next Token Not Found");
}

tuple<int,int,int,LexTokenType,string> Lexer::readDigit()
{

    return make_tuple(index, line, col, LexTokenType::ERROR, "Next Token Not Found");
}

tuple<int,int,int,LexTokenType,string> Lexer::readWord()
{

    return make_tuple(index, line, col, LexTokenType::ERROR, "Next Token Not Found");
}

//Returns next token for iteration.
tuple<int,int,int,LexTokenType,string> Lexer::nextToken()
{
    string lexValue = "";
    lexValue += advance();

    while(true)
    {
        if(reservedUnaryOpAndSingleSymbols.find(lexValue) != reservedUnaryOpAndSingleSymbols.end())
        {
            return make_tuple(index, line, col, reservedUnaryOpAndSingleSymbols[lexValue], lexValue);
        }
        else if(concatenatableSymbols.find(lexValue) != concatenatableSymbols.end())
        {
            if(lexValue.length() == 1)
            {
                if(concatenatableSymbols.find(lexValue + peek()) != concatenatableSymbols.end())
                {
                    lexValue += advance();
                }
            }
            return make_tuple(index, line, col, concatenatableSymbols[lexValue], lexValue);
        }
        else if(lexValue == "\"") //string
        {
            return readString();
        }
        else if(lexValue == "1") //digit
        {
            return readDigit();
        }
        else if(lexValue == "hi") //identifier or keyword
        {
            return readWord();
        }
        else { break; }
    }

    return make_tuple(index, line, col, LexTokenType::ERROR, "Next Token Not Found");
}

//----------------------------
//Create list of tokens
//----------------------------
void Lexer::createLexerTokens()
{
    tuple<int,int,int,LexTokenType,string> next = nextToken();
    srcTokens.push_back(next);
    
    while(get<3>(next) != LexTokenType::EOF_GOOD && get<3>(next) != LexTokenType::ERROR)
    {
        next = nextToken();
        srcTokens.push_back(next);
        cout << get<4>(next) << endl;
        break;
    }

    //Handle errors in here
    if(get<3>(next) == LexTokenType::ERROR)
    {
        cout << "Something went wrong in lexer" << endl;
    }

}

