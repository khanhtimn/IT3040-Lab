/*
Bài 2.7. Viết hàm tính tổng các phần tử trong hai mảng.

Yêu cầu sử dụng function template để cho phép hàm làm việc với các mảng số nguyên lẫn số thực.

For example:

Input	Result
5
31
31.4
*/

#include <iostream>

template <typename T>
T arr_sum(T* a, int n, T* b, int m)
{
    T sum = T();

    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    for (int i = 0; i < m; i++) {
        sum += b[i];
    }

    return sum;
}

int main()
{
    int val;
    std::cin >> val;

    {
        int a[] = { 3, 2, 0, val };
        int b[] = { 5, 6, 1, 2, 7 };
        std::cout << arr_sum(a, 4, b, 5) << std::endl;
    }
    {
        double a[] = { 3.0, 2, 0, val * 1.0 };
        double b[] = { 5, 6.1, 1, 2.3, 7 };
        std::cout << arr_sum(a, 4, b, 5) << std::endl;
    }

    return 0;
}
