/*

Cho một lược đồ gồm n cột chữ nhật liên tiếp nhau có chiều rộng bằng 1 và chiều cao lần lượt là các số nguyên không âm h1,h2,…,hn.
Hãy xác định hình chữ nhật có diện tích lớn nhất có thể tạo thành từ các cột liên tiếp.
Dữ liệu vào:
Dòng thứ nhất chứa số nguyên dương n (1≤n≤106).
Dòng thứ hai chứa n số nguyên không âm h1,h2,…,hn cách nhau bởi dấu cách (0≤hi≤109).
Kết quả:
In ra số nguyên duy nhất là diện tích hình chữ nhật lớn nhất có thể tạo thành từ các cột liên tiếp của lược đồ.
Ví dụ:
Dữ liệu vào:
7
6 2 5 4 5 1 6
Kết quả:
12
*/

#include <iostream>
#include <stack>
#include <vector>

long long n;
std::vector<long long> vt, L, R;

void inputData()
{
    std::cin >> n;
    vt.push_back(-1);
    for (long long i = 0; i < n; i++) {
        long long tmp;
        std::cin >> tmp;
        vt.push_back(tmp);
    }
    vt.push_back(-1);
}

void solve()
{
    while (true) {
        inputData();
        if (n == 0)
            return;

        std::stack<long long> st;
        L.resize(n + 2);
        R.resize(n + 2);
        for (long long i = 1; i <= n + 1; i++) {
            while (!st.empty() && vt[i] < vt[st.top()]) {
                L[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for (long long i = n; i >= 0; i--) {
            while (!st.empty() && vt[i] < vt[st.top()]) {
                R[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long maxh = 0;
        for (long long i = 1; i <= n; i++) {
            long long h = (L[i] - R[i] - 1) * vt[i];
            if (h > maxh)
                maxh = h;
        }

        std::cout << maxh << std::endl;
        break;

        vt.erase(vt.begin(), vt.end());
        L.erase(L.begin(), L.end());
        R.erase(R.begin(), R.end());
    }
}

int main()
{
    solve();
    return 0;
}
