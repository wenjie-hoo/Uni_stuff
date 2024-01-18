#include <iostream>
using namespace std;

template <int n>
struct Lucas {
    static const  int value = Lucas<n - 1>::value + Lucas<n - 2>::value;
};

template <>
struct Lucas<0> {
    static const int value = 2; 
};

template <>
struct Lucas<1> {
    static const int value = 1;  
};

int main() {
    constexpr int res = Lucas<5>::value;
    cout << "res: " << res <<endl;

    return 0;
}
