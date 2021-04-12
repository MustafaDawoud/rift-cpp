
rift: main.o rift_cpp_lexer.o
	g++ -std=c++11  main.o rift_cpp_lexer.o -o rift

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

rift_cpp_lexer.o: Lexer/rift_cpp_lexer.cpp Lexer/rift_cpp_lexer.h
	g++ -std=c++11 -c Lexer/rift_cpp_lexer.cpp

clean:
	rm *.o rift
