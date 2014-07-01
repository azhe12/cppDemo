#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/ptr_container/ptr_container.hpp>
#include <vector>

using namespace std;

class Foo {
    public:
        Foo()
        {
            cout<<"Foo constructor!"<<endl;
        }
        ~Foo()
        {
            cout<<"Foo distructor!"<<endl;
        }
};

vector<boost::shared_ptr<Foo> > v;

void test()
{
    boost::shared_ptr<Foo> f(new Foo());
    v.push_back(f);
}

int main()
{
    test();
    cout<<"test() end"<<endl;
    //v.pop_back();

    boost::ptr_vector<Foo> p_v;
    p_v.push_back(new Foo());

    cout<<"f2"<<endl;
    vector<Foo *> f2;
    f2.push_back(new Foo());
}
