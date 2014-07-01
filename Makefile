BINARIES:=	\
	singleton		\
	pthread_gettid	\
	testConst		\
	testBoostBind	\
	vector_sharedPtr	\
	dynamicPrograming	\
	bind_tst			\
	loopReference		\
	pthread_once		\
	pthread_tst			\
	ptr_vector			\
	shared_ptr_tst		\
	Singleton_test

all:${BINARIES}

CC:=g++
CXXFLAGS:=-g -pthread -std=c++0x

${BINARIES}:
	g++ ${CXXFLAGS} -o $@ $^

singleton:singleton.cpp
pthread_gettid:pthread_gettid.cpp
testConst:testConst.cc
testBoostBind:testBoostBind.cc
vector_sharedPtr:vector_sharedPtr.cpp
dynamicPrograming:dynamicPrograming.cpp
bind_tst:bind_tst.cpp
loopReference:loopReference.cpp
pthread_once:pthread_once.cpp
pthread_tst:pthread_tst.cpp
ptr_vector:ptr_vector.cc
shared_ptr_tst:shared_ptr_tst.cpp
Singleton_test:Singleton_test.cpp

synFlood:synFlood.c
	gcc -o $@ $^

clean:
	rm -rf $(BINARIES) *.o synFlood
