#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void countdown(uint time_to_last)
{
    this_thread::sleep_for(chrono::seconds(time_to_last));
    cout << 10 - time_to_last << " sec left."<< endl;
}

int main()
{
    thread t5{countdown, 5};
    thread t7{countdown, 7};
    thread t9{countdown, 9};
    thread t10([]()
               { this_thread::sleep_for(chrono::seconds(10)); });
    t5.join();
    t7.join();
    t9.join();
    t10.join();
    return 0;
}