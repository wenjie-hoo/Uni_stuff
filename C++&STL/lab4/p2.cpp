/* 
Implement a functor to assemble functions by executing them sequentially. 
The function po_college(f1, f2)(x) should execute first f1(x) and then f2(x). 
The values returned by these functions are to be ignored. The function po_kolei() should 
return a functor such that further folding is possible, for example po_kolei(po_kolei(f1, f2), f3)(x). 
Give an example of its use.
*/

#include <iostream>
#include <functional>
using namespace std;
struct po_college {
    function<void(int)> f1;
    function<void(int)> f2;
    po_college(function<void(int)> func1, function<void(int)> func2) : f1(func1), f2(func2) {}
    void operator()(int x) const {
        f1(x);
        f2(x);
    }
};

template<typename F1, typename F2>
auto po_kolei(F1 f1, F2 f2) {
    return po_college(f1, f2);
}

void printA(int x) {
    cout << "A ";
    }
void printB(int x) {
    cout << "B ";
    }
void printNumber(int x) {
    cout << "The number is: " << x << endl;
}

int main() {
    auto res1 = po_kolei((po_kolei(printA, printB), printNumber),printNumber);
    res1(1);
}
