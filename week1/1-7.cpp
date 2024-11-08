/*
   Bài 1.7. Viết chương trình nhập vào một mảng các số nguyên với số lượng các phần tử nhập từ bàn phím.
   Sau đó sắp xếp mảng theo thứ tự tăng dần. Hiển thị danh sách mảng trước và sau khi sắp xếp.

   Yêu cầu chỉ sử dụng con trỏ để truy cập mảng, không truy cập theo index mảng.

   For example:

   Input
   5
   9 -2 1 2 15
   Result
   Enter the number of elements: The input array is:
   9 -2 1 2 15
   The sorted array is:
   -2 1 2 9 15
   */
#include <iostream>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void bubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int size;
    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout << "The input array is:\n";
    printArray(arr, size);

    bubbleSort(arr, size);

    std::cout << "The sorted array is:\n";
    printArray(arr, size);

    delete[] arr;

    return 0;
}
