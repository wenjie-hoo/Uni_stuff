#include<iostream>

using namespace std;

template <int n, int k>
struct BinomialCoeff {
    static const int value = (n * BinomialCoeff<n-1, k-1>::value) / k;
};

template <int n>
struct BinomialCoeff<n, 0> {
    static const int value = 1;
};

template <int n>
struct BinomialCoeff<n ,n> {
    static const int value = 1;
};


int main() {
    constexpr int res = BinomialCoeff<10,3>::value;
    cout << "res: " << res <<endl;


    return 0;
}