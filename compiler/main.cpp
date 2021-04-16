#include <fstream>
#include "Lexer/Lexer.h"
#include <vector>
#include <tuple>

using namespace std;

int main(int argc, char *argv[])
{
    //TODO: Add command to run compiler using riftcpp.
    //TODO: Batch file reads instead of reading the entire file in one string

    //Print error message if file name is missing
    //TODO add flags
    if(argc <= 1)
    {
        cout << "File name is missing." << endl;
        return 1;
    }

    //Read rift file
    string src, line;
    ifstream file(argv[1]);
    if(file.is_open())
    {
        while(!file.eof())
        {
            getline(file, line);
            src.append(line);
        }
    }

    Lexer lex(src);
    vector<tuple<int,int,int,LexTokenType,string>> tokenList = lex.getSrcTokens();
    
    return 0;
}
