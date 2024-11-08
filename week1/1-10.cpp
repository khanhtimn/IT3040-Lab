/**
 * Viết chương trình nhập vào 2 ma trận vuông cùng kích thước n*n, trong đó n nhập từ bàn phím.
 * Sau đó tính tổng và tích của hai ma trận đó và đưa kết quả ra màn hình.
 * Yêu cầu sử dụng cấp phát động để cấp phát bộ nhớ cho các ma trận.
 * */
#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> A(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> A[i][j];
        }
    }

    std::vector<std::vector<int>> B(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> B[i][j];
        }
    }

    // Matrix sum
    std::vector<std::vector<int>> S(n, std::vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            S[i][j] = A[i][j] + B[i][j];
        }
    }

    for (const auto& row : S) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Matrix product
    std::vector<std::vector<int>> P(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                P[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (const auto& row : P) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
