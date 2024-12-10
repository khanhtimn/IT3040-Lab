/*
Bài 4.5. Viết hàm void dfs(vector< list<int> > adj) thực hiện thuật toán DFS không sử dụng đệ quy trên đồ thị biểu diễn bằng danh sách kề.
Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán DFS xuất phát từ đỉnh 1.
Các đỉnh được thăm theo thứ tự ưu tiên từ trái sang phải trong danh sách kề.
Yêu cầu hàm trả ra thứ tự các đỉnh được thăm (những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
*/

#include <iostream>
#include <list>
#include <stack>
#include <vector>

void dfs(std::vector<std::list<int>> adj)
{
    std::stack<int> S;
    std::vector<bool> visited(adj.size());
    S.push(1);
    while (!S.empty()) {
        int u = S.top();
        if (!visited[u]) {
            visited[u] = true;
            std::cout << u << std::endl;
        }
        if (!adj[u].empty()) {
            int v = adj[u].front();
            adj[u].pop_front();
            if (!visited[v]) {
                S.push(v);
            }
        } else {
            S.pop();
        }
    }
}

int main()
{
    int n = 7;
    std::vector<std::list<int>> adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
    return 0;
}
