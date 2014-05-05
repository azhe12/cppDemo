#include "Mutex.h"
#include <iostream>

using namespace std;

muduo::MutexLock mutex;

void f()
{
    assert(!mutex.isLockedByThisThread());
    muduo::MutexLockGuard lock(mutex);
}

int main()
{
    muduo::MutexLockGuard lock(mutex);
    f();
    return 0;
}
