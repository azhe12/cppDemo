#ifndef MUDUO_BASE_MUTEX_H
#define MUDUO_BASE_MUTEX_H

#include "Thread.h"
#include <boost/noncopyable.hpp>
#include <assert.h>
#include <pthread.h>

class Mutex : boost::noncopyable 
{
    public:
        Mutex()
            : holder_(0)
        {
            pthread_mutex_init(&mutex_, NULL);
        }
        ~Mutex()
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
            pthread_mutex_lock(&mutex_);
            holder_ = CurrentThread::tid();
        }

        void unlock()
        {
            holder_ = 0;
            pthread_mutex_unlock(&mutex_);
        }

    private:
        pthread_mutex_t mutex_;
        int holder_;
}

class MutexLockGard : boost::noncopyable
{
    public:

        MutexLockGard(MutexLock &mutex) : mutex_(mutex)
        {
            mutex_.lock();
        }

        ~MutexLockGard()
        {
            mutex_.unlock();
        }

    private:
        MutexLock mutex_;

}
// Prevent misuse like:
// MutexLockGuard(mutex_);
// A tempory object doesn't hold the lock for long!
#define MutexLockGuard(x) error "Missing guard object name"

#endif /*MUDUO_BASE_MUTEX_H*/
