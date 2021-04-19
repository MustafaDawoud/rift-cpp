rift: main.o Lexer.o
	g++ -Werror -std=c++11 main.o Lexer.o -o rift

main.o: main.cpp
	g++ -Werror -std=c++11 -c main.cpp

Lexer.o: Lexer/Lexer.cpp Lexer/Lexer.h
	g++ -Werror -std=c++11 -c Lexer/Lexer.cpp

clean:
	rm *.o rift
