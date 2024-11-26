/*
Cho đồ thị vô hướng G, hãy đếm số đường đi đi qua k cạnh và không đi qua đỉnh nào quá một lần.

Dữ liệu vào:

Dòng 1: Chứa hai số nguyên  n và k (1≤n≤30, 1≤k≤10) với n là số đỉnh của G.
Các đỉnh sẽ được đánh số từ 1 đến n

Dòng 2: Chứa số nguyên  m (1≤m≤60) là số cạnh của G

m dòng tiếp theo: Mỗi dòng chưa hai số nguyên là một cạnh của G

Kết quả:

Số lượng đường đi đơn độ dài  k

Ví dụ:

Dữ liệu mẫu:

4 3
5
1 2
1 3
1 4
2 3
3 4

Kết quả mẫu:

6
*/
#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int>> adj;
vector<bool> visited;
int result = 0;

void dfs(int v, int pathLen)
{
    if (pathLen == k) {
        result++;
        return;
    }

    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, pathLen + 1);
        }
    }
    visited[v] = false;
}

int main()
{
    cin >> n >> k >> m;

    adj.resize(n, vector<int>(n, 0));
    visited.resize(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u][v] = adj[v][u] = 1;
    }

    for (int i = 0; i < n; i++) {
        dfs(i, 0);
    }

    cout << result / 2 << endl;

    return 0;
}
