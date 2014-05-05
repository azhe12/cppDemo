#include <iostream>
#include <pthread.h>

using namespace std;

class Node {
    public:
        pthread_mutex_t mutex;
        int num;
}

void t1(Node * node) {

    
}
