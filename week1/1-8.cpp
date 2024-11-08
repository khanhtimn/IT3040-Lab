/*
   Bài 1.8. Viết chương trình nhập vào một ma trận 2 chiều kích thước m*n với m và n nhập từ bàn phím.
   Sau đó đưa ra tổng các phần tử chẵn của ma trận đó.

   Lưu ý: Khi viết hàm cấp phát bộ nhớ cho một ma trận hai chiều biểu diễn bởi con trỏ int **mt,
   nếu ta truyền con trỏ theo kiểu địa chỉ void allocate_mem(int **mt, int m, int n)
   sẽ dẫn tới việc cấp phát bộ nhớ cho một bản sao của con trỏ **mt.
   Do đó, sau khi gọi hàm thì con trỏ **mt gốc vẫn không được cấp phát bộ nhớ.
   Để cấp phát thành công cần truyền con trỏ theo dạng địa chỉ, ví dụ sử dụng con trỏ cấp 3 dạng int ***mt.

   For example:

   Input
   2 2
   1 2
   4 5
   Result
   Enter m, n = mt[0][0] = mt[0][1] = mt[1][0] = mt[1][1] = 1 2
   4 5
   The sum of all even elements is 6
   */
#include <iostream>

void allocate_mem(int*** mt, int m, int n)
{
    *mt = new int*[m];

    for (int i = 0; i < m; i++) {
        (*mt)[i] = new int[n];
    }
}

void free_mem(int** mt, int m)
{
    for (int i = 0; i < m; i++) {
        delete[] mt[i];
    }
    delete[] mt;
}

int sumEven(int** mt, int m, int n)
{
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mt[i][j] % 2 == 0) {
                sum += mt[i][j];
            }
        }
    }
    return sum;
}

int main()
{
    int m, n;
    int** mt;

    std::cout << "Enter m, n = ";
    std::cin >> m >> n;

    allocate_mem(&mt, m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "mt[" << i << "][" << j << "] = ";
            std::cin >> mt[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << mt[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "The sum of all even elements is " << sumEven(mt, m, n) << std::endl;

    free_mem(mt, m);

    return 0;
}
