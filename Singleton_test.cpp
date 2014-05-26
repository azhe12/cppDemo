#include <iostream>
#include "Singleton.h"
using namespace std;

class Foo {
    public:
        Foo()
        {
            cout<<"Foo constructor"<<endl;
        }
};

int main()
{
    Foo& f1 = Singleton<Foo>::instance();
    Foo& f2 = Singleton<Foo>::instance();
}
