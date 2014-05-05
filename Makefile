OBJ:=	\
	singleton

.PHONY:clean
CC:=g++
CPPFLAGS:='-g'

singleton:singleton.cpp
	g++ -pthread -std=c++0x -o singleton singleton.cpp

clean:
	rm -rf $(OBJ) *.o
