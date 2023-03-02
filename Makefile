main: main.cpp
	g++ -std=c++11 main.cpp Token.cpp Parser.h Scanner.cpp
	./a.out
