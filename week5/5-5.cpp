/*
Một năm được coi là nhuận nếu hoặc nó chia hết cho 4 nhưng không chia hết cho 100, hoặc nó chia hết cho 400.
Cho một danh sách các năm, kiểm tra xem có tồn tại năm nhuận trong danh sách đó hay không.
Mã nguồn sau giải quyết bài toán đó, hãy tinh chỉnh nó để tăng hiệu suất chương trình.
*/

#include <iostream>

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int year;
    bool found = false;

    while (std::cin >> year) {
        if (isLeapYear(year)) {
            found = true;
        }
    }

    std::cout << (found ? "Yes\n" : "No\n");
    return 0;
}
