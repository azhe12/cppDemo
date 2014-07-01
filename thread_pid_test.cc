#include <pthread.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <sys/unistd.h>

__thread int val;   //线程变量

pid_t getpid()
{
    return static_cast<pid_t>(syscall(SYS_gettid));
}
void * func(void * obj)
{
    printf("pid = %d, val=%d\n", getpid(), val);
}

int main()
{
    pthread_t pthreadId;
    val = 1;
    printf("pid = %d, val=%d\n", getpid(), val);

    if (pthread_create(&pthreadId, NULL, func, NULL)) {
        printf("failed to create thread\n");
    }
    pthread_join(pthreadId, NULL);
    return 0;
}
