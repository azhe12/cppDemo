#include <string>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
using namespace std;

class parent;
class children;

//typedef boost::shared_ptr<parent> parent_shared_ptr;
//typedef boost::shared_ptr<children> children_shared_ptr;
//typedef boost::weak_ptr<parent> parent_weak_ptr;
//typedef boost::weak_ptr<children> children_weak_ptr;

class parent
{
public:
    ~parent() { std::cout <<"destroying parent\n"; }

public:
    boost::weak_ptr<children> child;    //解除循环引用
    //boost::shared_ptr<children> child; //导致循环引用
};

class children
{
public:
    ~children() { std::cout <<"destroying children\n"; }

public:
    boost::shared_ptr<parent> par;
};

void test()
{
    boost::shared_ptr<parent> father(new parent);
    boost::shared_ptr<children> son(new children);

    father->child = son;
    son->par = father;
    //cout<<"use count:"<<father.use_count()<<" "<<son.use_count()<<endl;
}

int main()
{
    std::cout<<"begin test...\n";
    test();
    std::cout<<"end test.\n";
    return 0;
}
