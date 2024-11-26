/*
Trên bàn cờ vua kích thước n*n có một quân mã đang ở ô (1, 1).
Hãy đưa ra một dãy các di chuyển của mã sao cho mỗi ô trên bàn cờ đều được đi qua đúng 1 lần (ô (1, 1) được xem là đã đi qua).
*/
#include <iostream>
using namespace std;

int n, X[100], Y[100], mark[100][100];
const int hx[] = { 1, 1, 2, 2, -1, -1, -2, -2 };
const int hy[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

void print_sol()
{
    for (int j = 1; j <= n * n; ++j)
        cout << "(" << X[j] << " " << Y[j] << ")" << endl;
    exit(0);
}

void TRY(int k)
{
    for (int i = 0; i < 8; i++) {
        int xx = X[k - 1] + hx[i];
        int yy = Y[k - 1] + hy[i];
        if ((!mark[xx][yy]) && (1 <= xx) && (xx <= n) && (1 <= yy) && (yy <= n)) {
            X[k] = xx;
            Y[k] = yy;
            mark[xx][yy] = 1;
            if (k == n * n)
                print_sol();
            else
                TRY(k + 1);
            mark[xx][yy] = 0;
        }
    }
}
int main()
{
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
