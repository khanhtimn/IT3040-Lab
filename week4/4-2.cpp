/*

Một điểm trong không gian 2 chiều được biểu diễn bằng pair. Hãy viết hàm tính diện tích tam giác theo tọa độ 3 đỉnh.

double area(Point a, Point b, Point c) {

    # YOUR CODE HERE #

}

trong đó, Point là kiểu được định nghĩa trước trong trình chấm như sau:

using Point = pair<double, double>;

*/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>

using Point = std::pair<double, double>;

double area(Point a, Point b, Point c)
{
    return fabs(a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second)) / 2;
}

int main()
{
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << area({ 1, 2 }, { 2.5, 10 }, { 15, -5.25 }) << std::endl;
    return 0;
}
