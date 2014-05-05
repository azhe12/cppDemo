#ifndef MUDUO_BASE_MUTEX_H
#define MUDUO_BASE_MUTEX_H

#include "Thread.h"
#include <boost/noncopyable.hpp>
#include <assert.h>
#include <pthread.h>
#include <iostream>
namespace muduo {
    class MutexLock : boost::noncopyable 
    {
        public:
            MutexLock()
                : holder_(0)
            {
                //pthread_mutexattr_init(&attr);
                //pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ERRORCHECK_NP);
                pthread_mutex_init(&mutex_, NULL);
            }
            ~MutexLock()
            {
                assert(holder_ == 0);
                pthread_mutex_destroy(&mutex_);
            }
    
            bool isLockedByThisThread()
            {
                return holder_ == CurrentThread::tid();
            }
    
            void assertLocked()
            {
                assert(isLockedByThisThread());
            }
    
            void lock()
            {
                holder_ = CurrentThread::tid();
                std::cout<<"Tid: "<<holder_<<std::endl;
                pthread_mutex_lock(&mutex_);
            }
    
            void unlock()
            {
                holder_ = 0;
                pthread_mutex_unlock(&mutex_);
            }

            pthread_mutex_t * getPthreadMutex()
            {
                return &mutex_;
            }
    
        private:
            pthread_mutex_t mutex_;
            //pthread_mutexattr_t attr;
            pid_t holder_;
    };
    
    class MutexLockGuard : boost::noncopyable
    {
        public:
            MutexLockGuard(MutexLock& mutex) : mutex_(mutex)
            {
                mutex_.lock();
            }
    
            ~MutexLockGuard()
            {
                mutex_.unlock();
            }
    
        private:
            MutexLock & mutex_;
    
    };
}
// Prevent misuse like:
// MutexLockGuard(mutex_);
// A tempory object doesn't hold the lock for long!
#define MutexLockGuard(x) error "Missing guard object name"

#endif /*MUDUO_BASE_MUTEX_H*/
