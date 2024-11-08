/*
Bài 1.6. Viết hàm đảo ngược một mảng các số nguyên theo hai cách: dùng chỉ số và dùng con trỏ.

Ví dụ mảng đầu vào là [9, -1, 4, 5, 7] thì kết quả là [7, 5, 4, -1, 9].

void reversearray(int arr[], int size){

    int l = 0, r = size - 1, tmp;

    # YOUR CODE HERE #

}



void ptr_reversearray(int *arr, int size){

    int l = 0, r = size - 1, tmp;

    # YOUR CODE HERE #

}

For example:

Test
int arr[] = {9, 3, 5, 6, 2, 5};
reversearray(arr, 6);
for(int i = 0; i < 6; i++) cout << arr[i] << " ";
int arr2[] = {4, -1, 5, 9};
ptr_reversearray(arr2, 4);
for(int i = 0; i < 4; i++) cout << arr2[i] << " ";
Result
5 2 6 5 3 9 9 5 -1 4
*/
#include <iostream>

void reversearray(int arr[], int size)
{
    int l = 0, r = size - 1, tmp;
    while (l < r) {
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;

        l++;
        r--;
    }
}

void ptr_reversearray(int* arr, int size)
{
    int l = 0, r = size - 1, tmp;
    while (l < r) {
        tmp = *(arr + l);
        *(arr + l) = *(arr + r);
        *(arr + r) = tmp;

        l++;
        r--;
    }
}
int main()
{
    int arr[] = { 9, 3, 5, 6, 2, 5 };
    int size1 = sizeof(arr) / sizeof(arr[0]);

    reversearray(arr, size1);
    std::cout << "Reversed array using indices: ";
    for (int i = 0; i < size1; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    int arr2[] = { 4, -1, 5, 9 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    ptr_reversearray(arr2, size2);
    std::cout << "Reversed array using pointers: ";
    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
