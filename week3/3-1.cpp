/*
Dãy Lucas được định nghĩa bởi Ln = Ln-1 + Ln-2 với L0 = 2, L1 = 1.
Hãy viết hàm tính số Lucas thứ n.
*/
#include <iostream>

int lucas(int n)
{
    if (n <= 1)
        return 2 - n;
    return lucas(n - 1) + lucas(n - 2);
}

int main()
{
    int n;

    std::cin >> n;

    for (int i = 0; i <= n; i++) {
        std::cout << lucas(i) << std::endl;
    }

    return 0;
}
