/*
分别创建大小为10×10、100×100和1000×1000的矩阵，并用0.5到2.0范围内的随机值填充它们。
然后通过测量执行这些操作所需的时间来计算每个矩阵的平方。
使用 high_resolution_clock 时钟的 now() 函数测量时间。
对于小矩阵，重复操作多次，然后将测量时间除以该倍数。
*/

#include <iostream>
#include <functional>

// Functor to compose two functions f(g(x), h(x))
template <typename F, typename G, typename H>
struct compose_f_gx_hx {
    F f;
    G g;
    H h;

    compose_f_gx_hx(F f, G g, H h) : f(f), g(g), h(h) {}

    template <typename T>
    auto operator()(const T& x) {
        return f(g(x), h(x));
    }
};

// Example functions to use
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int square(int x) {
    return x * x;
}

int main() {
    // Creating the composed functor
    auto composed = compose_f_gx_hx<std::function<int(int, int)>, std::function<int(int)>, std::function<int(int)>>(add, square, multiply);

    // Example usage
    int value = 5;
    int result = composed(value);

    std::cout << "Result of f(g(x), h(x)) where x = " << value << " is: " << result << std::endl;

    return 0;
}
