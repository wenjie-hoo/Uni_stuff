// 使用模板使用静态有理算术定义初始谐波数ratio<>。您定义的最大谐波数是多少？
#include <iostream>
#include <ratio>
using namespace std;

template <int N>
class harmonic : public ratio_add<ratio<1, N>, harmonic<N - 1>>
{
};

template <>
class harmonic<1> : public ratio<1, 1>
{
};

int main()
{
    using n1 = harmonic<46>; //max 46
    cout << n1::num <<endl;
}