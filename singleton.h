#include <boost/noncopyable.hpp>
template<typename T>
class Singleton : boost::noncopyable{
    public:
        static void init()
        {
            val_ = new T();
        }
        static T& instance()
        {
            pthread_once(&ponce_, init);
            return *val_;
        }
    private:
        Singleton();
        ~Singleton();
        static pthread_once_t ponce_;
        static T* val_;
};

template<typename T>
pthread_once_t Singleton<T>::ponce_ = PTHREAD_ONCE_INIT;
template<typename T>
T* Singleton<T>::val_ = NULL;
