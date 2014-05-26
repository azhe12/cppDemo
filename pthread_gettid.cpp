#include <iostream>
#include <pthread.h>
#include "stdio.h"
#include <unistd.h>

//#include <sys/types.h>
#include "sys/types.h"
#include <sys/syscall.h>  
#define gettid() syscall(__NR_gettid)  

using namespace std;


void* func(void * args)
{
    //cout<<"Thread: "<<*(static_cast<int* >(args))<<" PID: "<<static_cast<unsigned long>(pthread_self())<<endl;
    printf("Thread: %d\t PID: %lu POSIX TID: %lu Kernel TID: %lu \n", *(static_cast<int* >(args)), (unsigned long)getpid(), static_cast<unsigned long>(pthread_self()), gettid());
    while (1) {}
}

int main()
{
    pthread_t t_array[8];

    printf("main----------\t PID: %lu POSIX TID: %lu Kernel TID: %lu \n",  (unsigned long)getpid(), static_cast<unsigned long>(pthread_self()), gettid());
    for (int i = 0; i < sizeof(t_array)/sizeof(pthread_t); i++) {
        pthread_create(&t_array[i], NULL, func, &i);
        //printf("t_array[%d]: %lu\n", i, (unsigned long)t_array[i]);
    }
    cout<<"main end"<<endl;
    while(1){};
}
