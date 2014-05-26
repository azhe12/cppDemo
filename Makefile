OBJ:=	\
	singleton		\
	pthread_gettid

.PHONY:clean
CC:=g++
CPPFLAGS:='-g'

singleton:singleton.cpp
	g++ -pthread -std=c++0x -o singleton singleton.cpp

pthread_gettid:pthread_gettid.cpp
	g++ -pthread -o pthread_gettid pthread_gettid.cpp

clean:
	rm -rf $(OBJ) *.o
