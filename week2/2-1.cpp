/*
Bài 2.1.  Viết hàm tính độ dài cạnh huyền của tam giác theo độ hai cạnh góc vuông.

For example:

Input	Result
3 4
z = 5.00
*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <ostream>

float get_hypotenuse(float x, float y)
{
    float z = std::pow(x, 2) + std::pow(y, 2);
    return std::sqrt(z);
}

int main()
{
    float x, y;

    std::cin >> x >> y;

    float z = get_hypotenuse(x, y);

    std::cout << "z = " << std::fixed << std::setprecision(2) << z << std::endl;

    return 0;
}
