#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include <chrono>
using namespace std;

const int BufferSize = 5;

queue<int> buffer;
mutex mtx;
condition_variable notFull, notEmpty;

void producer(int id)
{
    for (int i = 0; i < 10; ++i)
    {
        unique_lock<mutex> lock(mtx);
        notFull.wait(lock, []
                     { return buffer.size() < BufferSize; });

        int product = i + 1;
        buffer.push(product);
        cout << "Producer " << id << " produced: " << product << endl;

        // buffer is not empty
        notEmpty.notify_all();

        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

void consumer(int id)
{
    for (int i = 0; i < 10; ++i)
    {
        unique_lock<mutex> lock(mtx);

        notEmpty.wait(lock, []
                      { return !buffer.empty(); });

        int product = buffer.front();
        buffer.pop();
        cout << "Consumer " << id << " consumed: " << product << endl;

        notFull.notify_all();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main()
{
    thread producer1(producer, 1);
    thread producer2(producer, 2);
    thread consumer1(consumer, 1);
    thread consumer2(consumer, 2);

    producer1.join();
    producer2.join();
    consumer1.join();
    consumer2.join();

    return 0;
}
