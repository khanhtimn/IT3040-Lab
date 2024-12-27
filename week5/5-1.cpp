/*
Đoạn code sau liệt kê tất cả các hoán vị n số. Hãy tìm và sửa các lỗi cú pháp như hướng dẫn ở trên.
*/
#include <stdio.h>
int x[100], mark[100], n;
void print()
{
    for (int i = 1; i <= n; ++i)
        printf("%d ", x[i]);
    printf("\n");
}
void process(int i)
{
    if (i > n) {
        print();
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (!mark[j]) {
            mark[j] = 1;
            x[i] = j;
            process(i + 1);
            mark[j] = 0;
        }
}
int main()
{
    n = 5;
    process(1);
    return 0;
}
