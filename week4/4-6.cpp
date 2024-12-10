/*
Bài 4.6. Viết hàm void bfs(vector< list<int> > adj) thực hiện thuật toán BFS không sử dụng đệ quy trên đồ thị biểu diễn bằng danh sách kề.
Đồ thị có n đỉnh được đánh số từ 1 đến n. Thuật toán BFS xuất phát từ đỉnh 1.
Các đỉnh được thăm theo thứ tự ưu tiên từ trái sang phải trong danh sách kề.
Yêu cầu hàm trả ra thứ tự các đỉnh được thăm (những đỉnh không thể thăm từ đỉnh 1 thì không phải in ra).
*/

#include <iostream>
#include <list>
#include <queue>
#include <vector>

void bfs(std::vector<std::list<int>> adj)
{
    std::queue<int> Q;
    std::vector<bool> was(adj.size());
    Q.push(1);
    was[1] = true;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        std::cout << u << std::endl;
        for (int v : adj[u]) {
            if (!was[v]) {
                was[v] = true;
                Q.push(v);
            }
        }
    }
    std::cout << std::endl;
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
    bfs(adj);
    return 0;
}
