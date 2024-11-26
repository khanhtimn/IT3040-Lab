/*
Sử dụng phương pháp khử đệ quy bằng stack, hãy liệt kê các xâu nhị phân độ dài n không có k bit 1 nào liên tiếp

Dữ liệu vào:

Một dòng duy nhất chứa hai số nguyên n, k (1 ≤ k ≤ n ≤ 20)

Kết quả:

Với mỗi xâu tìm được, in ra  n ký tự trên một dòng, các ký tự cách nhau bởi dấu cách. Các xâu cần được liệt kê theo thứ tự từ điển.

For example:

Input
4 2

Result
0 0 0 0
0 0 0 1
0 0 1 0
0 1 0 0
0 1 0 1
1 0 0 0
1 0 0 1
1 0 1 0
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct state {
    int i, j, old_L;
    state(int _i = 0, int _j = 0, int _L = 0)
        : i(_i)
        , j(_j)
        , old_L(_L)
    {
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n + 1);
    stack<state> s;
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()) {
        state& top = s.top();
        if (top.i > n) {
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        if (top.j > 0)
            L = top.old_L;
        if (top.j > 1) {
            s.pop();
            continue;
        }
        if (L + 1 < k || top.j == 0) {
            x[top.i] = top.j;
            top.old_L = L;
            L = top.j ? L + 1 : 0;
            s.push(state(top.i + 1, 0));
        }
        ++top.j;
    }
    return 0;
}
