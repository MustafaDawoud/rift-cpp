
rift: main.o rift_cpp_lexer.o
	g++ main.o rift_cpp_lexer.o -o rift

main.o: main.cpp
	g++ -c main.cpp

rift_cpp_lexer.o: Lexer/rift_cpp_lexer.cpp Lexer/rift_cpp_lexer.h
	g++ -c Lexer/rift_cpp_lexer.cpp

clean:
	rm *.o rift
