#include <boost/bind.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>

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
    //A a(test);
    //boost::shared_ptr<A> aP(new A(test));
    boost::scoped_ptr<A> aP(new A(test));
    boost::function<void ()> f = boost::bind(&A::run, aP);
    f();
}
