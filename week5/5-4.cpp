/*
J. 04. CLOPAIR
- time limit per test: 1 second
- memory limit per test: 256 megabytes

Cho N điểm trên mặt phẳng, hãy tìm một cặp điểm với khoảng cách euclid nhỏ nhất giữa chúng.
Biết rằng không có hai điểm nào trùng nhau và có duy nhất một cặt có khoảng cách nhỏ nhất.

Input
Dòng đầu tiên chứa một số nguyên N(2≤N≤50000).
N dòng tiếp theo mỗi dòng chứa hai số nguyên là tọa độ X và Y của một điểm.
Giá trị tuyệt đối của X, Y không vượt quá 106.

Output
Ghi ra 3 số a, b, c, trong đó:
a, b (a<b) là các chỉ số của cặp điểm tìm được trong dữ liệu vào (chỉ số bắt đầu từ 0) và c là khoảng cách giữa chúng.
Làm tròn c đến 6 chữ số sau dấu phẩy động.

Examples
Input
5
0 0
0 1
100 45
2 3
9 9
Output
0 1 1.000000

Input
5
0 0
-4 1
-7 -2
4 5
1 1
Output
0 4 1.414214
*/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> c(n, vector<int>(n, 1e8));
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        c[x - 1][y - 1] = min(c[x - 1][y - 1], w);
    }
    int ans = 1e9;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    do {
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += c[p[i]][p[(i + 1) % n]];
        ans = min(ans, sum);
    } while (next_permutation(p.begin() + 1, p.end()));
    cout << ans << endl;
}
