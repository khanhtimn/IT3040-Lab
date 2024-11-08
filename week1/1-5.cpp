/*
Bài 1.5. Viết hàm trả về con trỏ trỏ tới giá trị lớn nhất của một mảng các số double. Nếu mảng rỗng hãy trả về NULL.

double* maximum(double* a, int size){

    double *max;

    max = a;

    if (a==NULL) return NULL;

    # YOUR CODE HERE #

    return max;

}

For example:

Test
double arr[] = {1., 10., 2., -7., 25., 3.};
double* max = maximum(arr, 6);
printf("%.0f", *max);
Result
25
*/
#include <cstddef>
#include <iostream>

double* maximum(double* a, int size)
{
    if (a == NULL || size <= 0)
        return NULL;

    double* max = a;

    for (int i = 1; i < size; i++) {
        if (*(a + i) > *max) {
            max = a + i;
        }
    }

    return max;
}

int main()
{
    double arr[] = { 1.0, 10.0, 2.0, -7.0, 25.0, 3.0 };
    int size = sizeof(arr) / sizeof(arr[0]);

    double* max = maximum(arr, size);

    if (max != NULL) {
        std::cout << "Maximum value: " << *max;
        std::cout << std::endl;
    } else {
        std::cout << "Array is empty.";
        std::cout << std::endl;
    }

    return 0;
}
