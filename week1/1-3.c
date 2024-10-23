/*
Bài 1.3. Viết chương trình yêu cầu nhập giá trị cho 3 biến số nguyên x, y, z kiểu int.
Sau đó sử dụng duy nhất một con trỏ để cộng giá trị của mỗi biến thêm 100.

#include <stdio.h>

int main() {

    int x, y, z;

    int *ptr;

    scanf("%d %d %d", &x, &y, &z);

    printf("Here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);

    # YOUR CODE HERE #

    printf("Once again, here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);

    return 0;

}

For example:

Input
25 50 75
Result
Here are the values of x, y, and z:
25 50 75
Once again, here are the values of x, y, and z:
125 150 175
*/
#include <stdio.h>

void add(int* ptr) {
    *ptr += 100;
}

int main() {

    int x, y, z;

    scanf("%d %d %d", &x, &y, &z);

    printf("Here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);

    add(&x);
    add(&y);
    add(&z);

    printf("Once again, here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);
    return 0;

}
