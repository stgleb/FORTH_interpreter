#include <thread>
#include <mutex>
#include <chrono>
#include <iomanip>
#include <iostream>

using namespace std;

mutex gil;

void show_lock(mutex& m) {
    char* ptr = (char*)(&m);
    cout<<hex<<endl;

    for(int i = 8;i < 13; i++) {
        cout<<(int)ptr[i];
    }
    cout<<endl;
}

void foo() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    while(!gil.try_lock()) {
        show_lock(gil);
    }
    show_lock(gil);

    gil.unlock();
}


void bar() {
    gil.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    gil.unlock();
}

int main() {
    thread t(foo);
    thread t2(bar);
    t.join();
    t2.join();
    return 0;
}