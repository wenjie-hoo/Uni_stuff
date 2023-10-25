#include <iostream>
#include <limits>
using namespace std;

int main()
{
    cout << numeric_limits<long long int>::min() << endl;
    cout << numeric_limits<long long int>::max() << endl;
    cout << numeric_limits<long long int>::digits << endl;
    cout << numeric_limits<long long int>::digits10 << endl;
    cout << numeric_limits<int>::min() << endl;
    cout << numeric_limits<int>::max() << endl;
}

#https: // en.cppreference.com/w/cpp/types/numeric_limits
