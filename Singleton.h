#include <pthread.h>

template<typename T>
class Singleton {
    public:
        static T& instance()
        {
            pthread_once(&ponce_, &init);
            return *val;
        }
    private:
        Singleton();
        ~Singleton();
        static void init()
        {
            val = new T();
        }

    private:
        static pthread_once_t ponce_;
        static T * val;
};

template<typename T>
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;

template<typename T>
T* Singleton<T>::val = NULL;
