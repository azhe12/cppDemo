#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/bind.hpp>
#include <utility>
#include <cstdio>
#include <queue>
#include <set>
//#include "Foo.h"
#include <sys/uio.h>
#include <string.h>
#include <poll.h>
using namespace std;

int main()
{
    struct pollfd pfd;
    pfd.fd = 1;
    //pfd.events = POLLOUT;
    pfd.events = POLLIN;
    pfd.revents = 0;
    const int timeout = 5000;
    char * s1 = "hello ";
    char * s2 = "world";
    struct iovec vec[2];
    vec[0].iov_base = s1;
    vec[0].iov_len = strlen(s1);
    vec[1].iov_base = s2;
    vec[1].iov_len = strlen(s2);
    char buf[100];

    int i = 0;
    while (1) {
        //if (i++ > 5) break;

        int numEvents = poll(&pfd, 1, timeout);
        if (numEvents > 0) {
            if (pfd.revents & POLLOUT) {
                writev(pfd.fd, vec, 2);
            } else if (pfd.revents & POLLIN) {
                int nRead = read(pfd.fd, buf, sizeof(buf));
                cout<<"Read: "<<buf<<endl;

            }
            cout<<endl;
        } else if (numEvents == 0) {
            cout<<"nothing happen"<<endl;
        } else {
            cout<<"error"<<endl;
        }
    
    }
}
