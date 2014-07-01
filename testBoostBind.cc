#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <iostream>
using namespace std;

typedef boost::function<void ()> FuncNoArg;

void funcA(FuncNoArg func)
{
    func();
}

void test()
{
    cout<<"test"<<endl;
}

class A {
public:
    A(FuncNoArg func) : func_(func)
    {}
    void funcM()
    {
        cout<<"A::funcM()"<<endl;
    }
    void run()
    {
        funcA(func_);
        funcA(boost::bind(&A::funcM, this));
    }
private:
    FuncNoArg func_;
};

int main()
{
    A a(test);
    a.run();
}
