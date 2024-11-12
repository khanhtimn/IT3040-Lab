/*
Bài 2.3. Viết chương trình yêu cầu nhập giá trị cho số nguyên x nhỏ hơn 100. In ra giá trị ax2+bx+c  với a, b, c định sẵn.

For example:

Input	Result
5 3 7 8
a=2, b=1, c=0: 55
a=3, b=1, c=0: 80
a=3, b=7, c=0: 110
a=3, b=7, c=8: 118
*/

#include <iostream>

int get_value(int x, int a = 2, int b = 1, int c = 0)
{
    return a * x * x + b * x + c;
}

int main()
{
    int x;
    std::cin >> x;

    int a = 2;
    int b = 1;
    int c = 0;

    std::cin >> a >> b >> c;

    std::cout << "a=2, b=1, c=0: " << get_value(x) << std::endl;
    std::cout << "a=" << a << ", b=1, c=0: " << get_value(x, a) << std::endl;
    std::cout << "a=" << a << ", b=" << b << ", c=0: " << get_value(x, a, b) << std::endl;
    std::cout << "a=" << a << ", b=" << b << ", c=" << c << ": " << get_value(x, a, b, c) << std::endl;

    return 0;
}
