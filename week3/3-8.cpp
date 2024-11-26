/*
Cân đĩa
Bạn đang muốn kiểm tra xem một vật cho trước có đúng nặng M như người ta nói hay không.
Có một cân thăng bằng và n quả cân. Quả thứ i nặng mi. Hãy chỉ ra một cách cân thỏa mãn.
Quy cách in ra đã được tích hợp trong mã nguồn dưới.

Dữ liệu mẫu:
6 10
7 1 2345

Kết quả mẫu:
-1+2+4+5=10
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
    int n, M;
    cin >> n >> M;
    stack<state> s;
    int sum = 0;

    vector<int> m(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> m[i];

    vector<int> x(n + 1);

    s.push(state(1, -1));

    while (!s.empty()) {
        state& top = s.top();
        if (top.i > n) {
            if (sum == M) {
                for (int i = 1; i <= n; ++i) {
                    if (x[i] == -1)
                        cout << "-" << m[i];
                    if (x[i] == 1)
                        cout << "+" << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            continue;
        }
        if (top.j > -1)
            sum -= m[top.i] * x[top.i];
        if (top.j > 1) {
            s.pop();
            continue;
        }
        x[top.i] = top.j;
        sum += m[top.i] * x[top.i];
        s.push(state(top.i + 1, -1));
        ++top.j;
    }

    cout << -1;

    return 0;
}
