/*
Superior là một hòn đảo tuyệt đẹp với n địa điểm chụp ảnh và các đường một chiều nối các điểm chụp ảnh với nhau.
Đoàn khách tham quan có r người với sở thích chụp ảnh khác nhau. Theo đó, mỗi người sẽ đưa ra danh sách các địa điểm mà họ muốn chụp.
Bạn cần giúp mỗi người trong đoàn lập lịch di chuyển sao cho đi qua các điểm họ yêu cầu đúng một lần, không đi qua điểm nào khác,
bắt đầu tại điểm đầu tiên và kết thúc tại điểm cuối cùng trong danh sách mà họ đưa ra, và có tổng khoảng cách đi lại là nhỏ nhất.

Dữ liệu vào:

Dòng đầu chứa n và r

Tiếp theo là ma trận n×n mô tả chi phí đi lại giữa các địa điểm. Chi phí bằng 0 có nghĩa là không thể đi lại giữa hai địa điểm đó.

r dòng tiếp theo chứa danh sách các địa điểm mà người r đưa ra.
Lưu ý là hành mỗi hành trình cần phải bắt đầu và kết thúc bởi hai đỉnh đầu và cuối của danh sách, còn các địa điểm còn lại có thể thăm theo bất kỳ thứ tự nào

Kết quả:

Gồm r dòng ghi chi phí đi lại ít nhất của r người theo thứ tự đầu vào

Ví dụ:

Dữ liệu mẫu:

6 3
0 1 2 0 1 1
1 0 1 1 1 0
0 2 0 1 3 0
4 3 1 0 0 0
0 0 1 1 0 0
1 0 0 0 0 0
1 3 5
6 3 2 5
6 1 2 3 4 5

Kết quả mẫu:

5
0
7
*/
// TODO: Needs input santitation
#include <climits>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

const int MAX = 20;
int n, r, price[MAX][MAX];
int x[MAX], best, sum_price, start, des, numOfPoint;
bool visited[MAX];
vector<int> vt;

inline void inputData()
{
    cin >> n >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> price[i][j];
}

inline bool check(int a, int i)
{
    return !visited[vt[i]] && price[x[a - 1]][vt[i]];
}

inline void solution()
{
    if (price[x[numOfPoint - 2]][des])
        best = min(best, sum_price + price[x[numOfPoint - 2]][des]);
}

void TRY(int k)
{
    for (int i = 1; i < numOfPoint - 1; i++) {
        if (check(k, i)) {
            visited[vt[i]] = true;
            sum_price += price[x[k - 1]][vt[i]];
            x[k] = vt[i];

            if (k == numOfPoint - 2)
                solution();
            else
                TRY(k + 1);

            visited[vt[i]] = false;
            sum_price -= price[x[k - 1]][vt[i]];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    inputData();
    cin.ignore();

    while (r--) {
        best = INT_MAX;
        sum_price = 0;
        vt.clear();

        getline(cin, str);
        stringstream ss(str);
        int tmp;
        while (ss >> tmp)
            vt.push_back(tmp - 1);

        start = vt.front();
        des = vt.back();
        numOfPoint = vt.size();
        x[0] = start;
        x[numOfPoint - 1] = des;
        fill(visited, visited + n, false);

        TRY(1);
        cout << (best == INT_MAX ? 0 : best) << '\n';
    }
}
