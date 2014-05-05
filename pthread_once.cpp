#include <iostream>
#include <thread>

using namespace std;

void init()
{
    cout<<"init"<<endl;
}

int main()
{
    pthread_once_t once = PTHREAD_ONCE_INIT;
    pthread_once(&once, init);
    pthread_once(&once, init);
    pthread_once(&once, init);
}
