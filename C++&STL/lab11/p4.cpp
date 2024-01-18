#include <iostream>

template <size_t N, typename T>
struct DotProduct {
    static constexpr T result(const T *a, const T *b) {
        return *a * *b + DotProduct<N - 1, T>::result(a + 1, b + 1);
    }
};

template <typename T>
struct DotProduct<0, T> {
    static constexpr T result(const T *, const T *) {
        return T{};
    }
};

int main() {
    int v1[4] = {4, 3, 7, 4};
    int v2[4] = {3, 4, 5, 6};
    // 4*3+3*4+7*5+4*6=83
    std::cout << "res: " << DotProduct<4, int>::result(v1, v2) << std::endl;

    return 0;
}
