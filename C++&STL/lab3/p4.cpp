/*
定义一个函数模板，将值从指定对象传输到另一个对象。
考虑到两个方面：首先，源对象可以由值/引用或指针来指定（使用典型特征来区分这两种情况），
其次，is_pointer<>目标对象是由引用来指示的，不一定是由引用来指示的相同类型
（使用典型特征确定转换的可能性is_convertible<>）。
*/

#include <iostream>
#include <type_traits>
using namespace std;

template <typename T1, typename T2>
void carry(T1 num1, T2 &num2)
{
    if constexpr (is_pointer_v<T1>)
    {
        if constexpr (is_convertible_v<decltype(*num1), T2>)
        {
            num2 = std::move(static_cast<T2>(*num1));
        }
        else
        {
            throw logic_error("Conversion not possible");
        }
    }
    else
    {
        if constexpr (is_convertible_v<T1, T2>)
        {
            num2 = move(num1);
        }
        else
        {
            throw logic_error("Conversion not possible");
        }
    }
}

int main()
{
    int x = 1;
    double y;
    carry(&x, y);
    std::cout << "y: " << y << std::endl;

    return 0;
}
