/*
Cho dãy a có n phần tử.
Một dãy con của a là dãy thu được bằng cách xóa đi một số phần tử của a và giữ nguyên thứ tự các phần tử còn lại (có thể không xóa phần tử nào).
Hãy tìm dãy con tăng dài nhất của a.

Dữ liệu vào:

Dòng 1: Chứa số nguyên n (1≤n≤1000)

Dòng 2: Chứa n số nguyên a1, a2,..., an (|ai| ≤10^9)

Kết quả:

Dòng đầu tiên chứa độ dài dãy con tăng dài nhất

Dòng thứ 2 chứa chỉ số các phần tử được chọn vào dãy con đó

Nếu có nhiều dãy con tăng dài nhất, in ra dãy bất kỳ trong số đó

For example:

Input
6
2 1 5 4 3 6

Result
3
2 5 6
*/
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int a[1000], n;
int mem[1000];

void init()
{
    memset(mem, -1, sizeof(mem));
}

int lis(int i)
{
    if (mem[i] != -1) {
        return mem[i];
    }
    int res = 1;
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i]) {
            res = max(res, 1 + lis(j));
        }
    }
    mem[i] = res;
    return res;
}

void trace(int i)
{
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i] && mem[i] == 1 + mem[j]) {
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main()
{
    init();
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int res = 1, pos = 0;
    for (int i = 1; i < n; i++) {
        if (res < lis(i)) {
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
