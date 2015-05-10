#include <iostream>
#include <thread>
#include <mutex>
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;

union un{
    mutex gil;
    char ch[40];
};


void foo() {
    mutex l;
    char* before = new char[40];
    char* after = new char[40];

    char* ptr = (char*)(&l);

    for(int i = 0; i < sizeof(l); i++) {
        before[i] = ptr[i];
    }

    cout<<endl;
    l.lock();
    for(int i = 0; i < sizeof(l); i++) {
        after[i] = ptr[i];
    }
    l.unlock();

    for(int i = 0; i < sizeof(l); i++) {
        if(after[i] != before[i]) {
            cout<< i << endl;
        }
    }
}

int main() {

    thread t(foo);
    t.join();
    return 0;
}