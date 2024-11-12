/*
Bài 2.4. Viết các hàm tính lập phương của số nguyên và số thực.

For example:

Input	Result
3 5.2
Int: 27
Double: 140.61
*/

#include <iomanip>
#include <iostream>

int cube(int x)
{
    return x * x * x;
}

double cube(double x)
{
    return x * x * x;
}

int main()
{
    int n;
    double f;
    std::cin >> n >> f;

    std::cout << "Int: " << cube(n) << std::endl;
    std::cout << "Double: " << std::fixed << std::setprecision(2) << cube(f) << std::endl;

    return 0;
}
