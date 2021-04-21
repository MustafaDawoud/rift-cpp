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

     //Data types
     //{"string", LexTokenType::STRING_TYPE}
};

unordered_map<string, LexTokenType> Lexer::unaryOpAndSingleSymbols = 
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
            c = src[index++];
        }
        else if(c == ' ' || c == '\t')
        {
            col++;
            c = src[index++];
        }
        else
        {
            col++;
            break;
        }
    }

    return c;
}

tuple<int,int,int,LexTokenType,string> Lexer::readString(string lexValue)
{
    char c = advance();
    
    while(true)
    {
        if(isEnd()) { break; }
        else
        {
            lexValue += c;
            if(c == '\"')
            {
                return make_tuple(index, line, col, LexTokenType::STRING_LIT, lexValue);
            }
        }
    }
    return make_tuple(index, line, col, LexTokenType::ERROR, lexValue);
}

tuple<int,int,int,LexTokenType,string> Lexer::readInteger(string lexValue)
{
    while(true)
    {
        if(isdigit(peek()))
        {
            lexValue += advance();
        }
        else
        {
            return make_tuple(index, line, col, LexTokenType::INT_LIT, lexValue);
        }
    }

    return make_tuple(index, line, col, LexTokenType::ERROR, lexValue);
}

tuple<int,int,int,LexTokenType,string> Lexer::readName(string lexValue)
{
    while(true)
    {
        char p = peek();
        cout << "Lex value: " << lexValue <<" "<< p >= 'A' <<" "<< p <= 'z' <<" "<< isdigit(p) <<" "<< p == '_' << endl;
        if ((p >= 'A' && p <= 'z') || isdigit(p) || p == '_') 
        {
            lexValue += advance();
            if(reservedKeywords.find(lexValue) != reservedKeywords.end())
            {
                return make_tuple(index, line, col, reservedKeywords[lexValue], lexValue);
            }
        }
        else
        {
            return make_tuple(index, line, col, LexTokenType::ID, lexValue);
        }
    }

    return make_tuple(index, line, col, LexTokenType::ERROR, lexValue);
}

//Returns next token for iteration.
tuple<int,int,int,LexTokenType,string> Lexer::nextToken()
{
    char c = advance();
    string lexValue = "";
    lexValue += c;
    cout << c << endl;

    while(true)
    {
        if(unaryOpAndSingleSymbols.find(lexValue) != unaryOpAndSingleSymbols.end())
        {
            return make_tuple(index, line, col, unaryOpAndSingleSymbols[lexValue], lexValue);
        }
        else if(concatenatableSymbols.find(lexValue) != concatenatableSymbols.end())
        {
            lexValue += advance();
            if(concatenatableSymbols.find(lexValue + peek()) != concatenatableSymbols.end())
            {
                lexValue += advance();
            }
            return make_tuple(index, line, col, concatenatableSymbols[lexValue], lexValue);
        }
        else if(c == '\"') //string
        {
            return readString(lexValue);
        }
        else if(isdigit(c)) //digit
        {
            if(c == '0')
            {
                return make_tuple(index, line, col, LexTokenType::ERROR, "Cannot start integer with 0");
            }
            return readInteger(lexValue);
        }
        else if(c == '_' || (c >= 'A' && c <= 'z')) //name or keyword
        {
            cout << "read name" << endl;
            return readName(lexValue);
        }
        //else if(c == ' ' || c == '\n' || c == '\t'){ continue; }
        else { break; }
    }

    cout << "exiting" << endl;
    //Generic Error
    return make_tuple(index, line, col, LexTokenType::ERROR, lexValue);
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
        cout << "Next token returned value: " << get<4>(next) << endl;
        next = nextToken();
        srcTokens.push_back(next);
    }

    //Handle errors in here
    if(get<3>(next) == LexTokenType::ERROR)
    {
        cout << "Something went wrong in lexer" << endl;
    }

}

