/**
 * Viết chương trình in ra tất cả các dãy con của một dãy cho trước.
 * Ví dụ dãy 1 3 4 2 có các dãy con sau:
 * 1
 * 1 3
 * 1 3 4
 * 1 3 4 2
 * 3
 * 3 4
 * 3 4 2
 * 4
 * 4 2
 * 2
 * */

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n) {
            for (int k = i; k <= j; k++) {
                std::cout << arr[k] << " ";
            }
            std::cout << std::endl;
            j++;
        }
    }

    return 0;
}
