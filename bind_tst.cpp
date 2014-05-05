#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>

using namespace std;

void foo(int x, int y)
{
    cout<<x<<" "<<y<<endl;
}

int main()
{
    //boost::function<void(int x, int y)> f;
    boost::function<void(int)> f;
    //boost::bind(&foo, 1, _1)(2);
    f = boost::bind(&foo, 1, _1)(2);
    //f(2);
    //boost::bind(&foo, 1, 2)();
    //f();
    return 0;
}
