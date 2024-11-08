/*
Bài 1.1. Viết một chương trình C nhập vào 3 số nguyên. Thiết lập một con trỏ để lần lượt trỏ tới từng số nguyên và hiển thị kết quả giá trị tham chiếu ngược của con trỏ.

Lưu ý: Phép toán & trả về địa chỉ của biến.

For example:

Input
3 4 5
Result
Enter three integers:
The three integers are:
x = 3
y = 4
z = 5
*/
#include <iostream>

int main()
{
    int x, y, z;

    std::cout << "Enter three integers: ";
    std::cin >> x >> y >> z;

    std::cout << "\nThe three integers are:\n";
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;

    return 0;
}
