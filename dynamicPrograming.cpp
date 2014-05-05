#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

vector<int> f(3,1);
/*  动态规划方式 求fib
 *  存储中间值
 * */
int fib_dp(int n)
{
    if (n == 0)
        return 0;
    if (n >= f.size())
        f.resize(n+1);

    if (f[n] == 0)  /*未存储, 递归计算*/
        f[n] = fib_dp(n-1) + fib_dp(n-2);
    else            /*已存储*/
        return f[n];
}

int fib_noDP(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return 1;

    return fib_noDP(n-1) + fib_noDP(n-2);
}
int main()
{
    int n;
    int val;
    clock_t start, finish;
    double elapse;
    f[0] = 0;
    cout<<"Enter n: ";
    while (cin>>n) {
        /*DP*/
        start = clock();
        for (int i = 0; i < 10000000; i++) {
            val = fib_dp(n);
        }
        finish = clock();
        elapse = (double)(finish - start) / CLOCKS_PER_SEC;
        cout<<"Fibs: "<<val<<" DP Elapse: "<<elapse<<endl;

        /*no DP*/
        start = clock();
        for (int i = 0; i < 10000000; i++) {
            val = fib_noDP(n);
        }
        finish = clock();
        elapse = (double)(finish - start) / CLOCKS_PER_SEC;
        cout<<"Fibs: "<<val<<" noDP Elapse: "<<elapse<<endl;
 
        cout<<"Enter n: ";
    }
    return 0;
}
