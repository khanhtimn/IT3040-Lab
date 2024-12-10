/*
Một vector trong không gian 3 chiều được biểu diễn bằng tuple<double, double, double>. Hãy viết hàm tính tích có hướng của 2 vector.

Vector cross_product(Vector a, Vector b) {

    # YOUR CODE HERE #

}

trong đó Vector là kiểu được định nghĩa sẵn trong trình chấm như sau:

using Vector = tuple<double, double, double>;
*/

#include <iomanip>
#include <iostream>
#include <tuple>

using Vector = std::tuple<double, double, double>;

Vector cross_product(Vector a, Vector b)
{
    return std::make_tuple(
        std::get<1>(a) * std::get<2>(b) - std::get<2>(a) * std::get<1>(b),
        -(std::get<0>(a) * std::get<2>(b) - std::get<2>(a) * std::get<0>(b)),
        std::get<0>(a) * std::get<1>(b) - std::get<1>(a) * std::get<0>(b));
}

int main()
{
    std::cout << std::setprecision(2) << std::fixed;
    Vector a { 1.2, 4, -0.5 };
    Vector b { 1.5, -2, 2.5 };
    Vector c = cross_product(a, b);
    std::cout << std::get<0>(c) << " " << std::get<1>(c) << " " << std::get<2>(c) << std::endl;
    return 0;
}
