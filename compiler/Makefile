rift: main.o rift_cpp_lexer.o LexTokens.o
	g++ -std=c++11 main.o rift_cpp_lexer.o LexTokens.o -o rift

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

rift_cpp_lexer.o: Lexer/rift_cpp_lexer.cpp Lexer/rift_cpp_lexer.h
	g++ -std=c++11 -c Lexer/rift_cpp_lexer.cpp

LexTokens.o: Lexer/LexTokens.cpp Lexer/LexTokens.h
    g++ -std=c++11 -c Lexer/LexTokens.cpp

clean:
	rm *.o rift
