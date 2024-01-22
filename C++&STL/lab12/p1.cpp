#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
using namespace std;

void printName(const string& name) {
    while (true) {
        cout << "Thread " << name << " is running." << endl;
        this_thread::sleep_for(chrono::milliseconds(rand() % 501 + 500));
    }
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    vector<string> thread_names = {"thread-A", "thread-B", "thread-C"};
    vector<thread> threads;

    for (const auto& name : thread_names){
        threads.emplace_back(printName, name);
    }

    this_thread::sleep_for(chrono::minutes(1));
    for (auto& thread : threads) {
        thread.detach();
    }
    return 0;
}
