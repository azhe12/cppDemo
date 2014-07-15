#include <iostream>
using namespace std;

class A {
    public:
        void run() const
        {
            cout<<"A::run()"<<endl;
        }

};
void test(const A& a)
{
    a.run();
}
int main()
{
    A a;
    test(a);
    a.run();
    return 0;
}
