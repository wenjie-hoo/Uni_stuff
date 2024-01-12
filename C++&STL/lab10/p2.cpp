#include <iostream>
#include <iomanip>
#include <chrono>

using namespace std;

int main() {
    int intData = 42;
    float floatData = 3.14;
    double doubleData = 2.71228;

    double money1 = 100.501;
    double money2 = 49.9;

    auto currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    
    cout << fixed << setprecision(2) << endl;

    cout << "int: " << intData << endl;
    cout << "float: " << floatData << endl;
    cout << "double: " << doubleData << endl;

    cout << "money 1:" << money1 << endl;
    cout << "money 2:" << money2 << endl;

    cout << "Date and Time: " << put_time(localtime(&currentTime), "%Y-%m-%d %X") << endl;

    return 0;
}
