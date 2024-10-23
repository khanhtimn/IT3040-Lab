/*
Bài 1.4. Viết hàm countEven(int*, int) nhận một mảng số nguyên và kích thước của mảng,
trả về số lượng số chẵn trong mảng???

For example:

Test
int arr[] = {1, 5, 4, 8, 10, 6, 7, 2};
Result
cout << counteven(arr, 8);
5
*/
#include <stdio.h>
#include <stdlib.h>

int counteven(int* ptr, int size) {
    int total = 0;
    for(int i = 0; i < size; ++i) {
        if ((*(ptr + i) % 2) == 0) ++total;
    }
    return total;
}
