#include <iostream>
#include "boost/shared_ptr.hpp"
#include <boost/scoped_ptr.hpp>
using namespace std;
class T {
    public:
        int val;
        //T() {}
        //T(int val):(val) {}
        ~T() {cout<<"delete T"<<endl;}
};

void test(T* t)
{
    cout<<"test()"<<endl;
}

int main()
{
#if 0
    boost::shared_ptr<int> a(new int(10));
    boost::shared_ptr<int> b(a);
    boost::shared_ptr<int> c(a);

    *a = 20;
    cout<<*b<<" "<<*c<<endl;
#endif
    {
#if 0
        T* a = new T;
        T* b = a;
        T* c = a;
#endif
#if 1
        boost::shared_ptr<T> a(new T);
        boost::shared_ptr<T> f(new T);
        boost::scoped_ptr<T> g(new T);
        test(a.get());
        test(get_pointer(g));

        a = f;
        //cout<<"a use_count: "<<a.use_count()<<endl;
        cout<<"end of critical"<<endl;
        cout<<"f use count: "<<f.use_count()<<endl;
#endif
    }
    cout<<"program end"<<endl;
}
