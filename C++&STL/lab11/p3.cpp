#include<iostream>
#include <iostream>

template < int A, unsigned int B>
struct GCD {
    static const  int value = GCD<B, A % B>::value;
};

template < int A>
struct GCD<A, 0> {
    static const int value = A;
};

int main() {    
    constexpr int res = GCD<32,24>::value;
    std::cout << "res: " << res << std::endl;

    return 0;
}
