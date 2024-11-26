/*
Tính hệ số tổ hợp C(n, k)

For example:

Input
4

Result
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/
#include <iostream>

using namespace std;

int c[1000][1000];

int binom(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 0)
        return 1;
    return binom(n - 1, k) + binom(n - 1, k - 1);
}

int binom2(int n, int k)
{
    for (int i = 0; i <= n; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    return c[n][k];
}

int main()
{
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n) {
        for (int k = 0; k <= n; ++k)
            cout << binom(n, k) << " ";
        cout << endl;
    }
    for (int n = 1; n <= m; ++n) {
        for (int k = 0; k <= n; ++k)
            cout << binom2(n, k) << " ";
        cout << endl;
    }
    return 0;
}
