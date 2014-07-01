#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
//#include <boost/unique_ptr.hpp>

#include <boost/bind.hpp>
#include <utility>
#include <cstdio>
#include <queue>
#include <set>
//#include "Foo.h"
#include <sys/uio.h>
//#include <string.h>
#include <strings.h>
#include <poll.h>
#include <sstream>
#include <boost/ptr_container/ptr_vector.hpp>
using namespace std;


void func(int val, int n)
{
    cout<<val<<" "<<n<<endl;
}

template <typename To, typename From>
To implicit_cast(const From & val)
{
    return val;
}

class A {
public:
    A() : val_(0)
    {
        cout<<"A ctor"<<endl;
    }
    A(A& obj)
    {
        val_ = obj.val_;
        cout<<"copy ctor"<<endl;
    }
    ~A()
    {
        cout<<"A dtor"<<endl;
    }
    int val()
    {
        return val_;
    }
private:
    int val_;
};

//typedef unique_ptr<A> APtr;
typedef shared_ptr<A> APtr;
vector<APtr> v;

void test()
{
    APtr pA(new A);
    v.push_back(pA);
    cout<<"test() end"<<endl;
}

void printStr(const char*  str)
{
    printf("%s\n", str);
}

int main()
{
    //vector<A*> v;
    boost::ptr_vector<A> v;
    for (int i = 0; i < 5; i++) {
        A* pA = new A;
        v.push_back(pA);
    }
    return 0;
}

