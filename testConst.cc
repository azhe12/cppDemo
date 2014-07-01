#include <iostream>
using namespace std;

class A {
    public:
        void run()
        {
            cout<<"A::run()"<<endl;
        }
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
    return 0;
}
