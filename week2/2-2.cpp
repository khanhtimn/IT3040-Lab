/*
Bài 2.2. Viết hàm hoán vị vòng tròn 3 biến a, b, c. Sau khi thực hiện hàm, các biến a, b, c tương ứng nhận các giá trị mới b, c, a.

For example:

Input	Result
3 4 5
Before: 3, 4, 5
After: 4, 5, 3
*/

#include <iostream>
#include <ostream>

void rotate(int& x, int& y, int& z)
{
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main()
{
    int x, y, z;

    std::cin >> x >> y >> z;

    std::cout << "Before: " << x << ", " << y << ", " << z << std::endl;

    rotate(x, y, z);

    std::cout << "After: " << x << ", " << y << ", " << z << std::endl;

    return 0;
}
