#include <iostream>
using namespace std;

class Lexer 
{
	private:
		string src;
	public:
		Lexer(string src);
		void nextToken();
};
