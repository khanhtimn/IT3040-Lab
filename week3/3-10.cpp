/*
Khoảng cách Hamming giữa hai xâu cùng độ dài là số vị trí mà ký tự tại vị trí đó là khác nhau trên hai xâu.
Cho S là xâu gồm n ký tự 0. Hãy liệt kê tất cả các xâu nhị phân độ dài n, có khoảng cách Hamming với S bằng H.
Các xâu phải được liệt kê theo thứ tự từ điển.

Dữ liệu vào:

Dòng đầu chứa T là số testcase

T dòng tiếp theo, mỗi dòng mô tả một testcase, ghi N và H (1≤H≤N≤16)

Kết quả:

Với mỗi testcase, in ra danh sách các xâu thỏa mãn. In ra một dòng trống giữa hai testcase

Ví dụ:

Dữ liệu mẫu:

2
4 2

1 0

Kết quả mẫu:

0011
0101
0110
1001
1010
1100

0
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string current;
vector<string> results;

void generate(int pos, int remainingOnes, int n)
{
    if (remainingOnes == 0) {
        results.push_back(current);
        return;
    }

    if (pos >= n || remainingOnes > n - pos)
        return;

    current[pos] = '1';
    generate(pos + 1, remainingOnes - 1, n);

    current[pos] = '0';
    generate(pos + 1, remainingOnes, n);
}

void solve(int n, int h)
{
    if (h == 0) {
        if (n == 0)
            return;
        cout << string(n, '0') << endl;
        return;
    }

    if (h > n || h < 0) {
        return;
    }

    results.clear();
    current = string(n, '0');

    generate(0, h, n);

    reverse(results.begin(), results.end());

    for (const string& result : results) {
        cout << result << endl;
    }
}

int main()
{
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, H;
        cin >> N >> H;

        solve(N, H);

        if (t < T - 1) {
            cout << endl;
        }
    }

    return 0;
}
