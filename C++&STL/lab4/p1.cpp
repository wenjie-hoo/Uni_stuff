// Implement the functor compose_f_gx_hx implementing the binary complex f(g(x), h(x)). Give an example of its use.

#include <iostream>
#include <functional>
using namespace std;

template<typename F, typename G, typename H>
struct compose_f_gx_hx {
    F f;
    G g;
    H h;
    compose_f_gx_hx(F f, G g, H h) : f(f), g(g), h(h) {}
    template<typename T>
    auto operator()(T x) const {
        return f(g(x), h(x));
    }
};

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b){
    return a-b;
}

int square(int x) {
    return x * x;
}

int doubleValue(int x) {
    return 2 * x;
}

int main() {
    function<int(int, int)> addFunc = add;
    function<int(int)> squareFunc = square;
    function<int(int)> doubleValueFunc = doubleValue;
    function<int(int, int)> subtractFunc  = subtract;
    compose_f_gx_hx<decltype(addFunc), decltype(squareFunc), decltype(doubleValueFunc)> func1(addFunc, squareFunc, doubleValueFunc);
    compose_f_gx_hx<decltype(subtractFunc), decltype(squareFunc), decltype(doubleValueFunc)> func2(subtractFunc, squareFunc, doubleValueFunc);
    
    int x = 5;
    int res1 = func1(x);
    cout << "Res1:" << res1 << endl;

    int res2 = func2(x);
    cout << "Res2:" << res2 << endl;
    return 0;
}
