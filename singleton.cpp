#include <iostream>
#include <thread>
#include "singleton.h"

using namespace std;

class Foo {
    public:
        Foo()
        {}
        void print()
        {
            cout<<val<<endl;
        }
    private:
        int val;
};
int main()
{
    /*只会存在一个singleton对象，f和f1的地址相同*/
    Foo& f = Singleton<Foo>::instance();
    //f.print();
    cout<<&f<<endl;
    Foo& f1 = Singleton<Foo>::instance();
    //f1.print();
    cout<<&f1<<endl;
}
