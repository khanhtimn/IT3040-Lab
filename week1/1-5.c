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
double* maximum(double* a, int size) {
    if (a == NULL || size <= 0) return NULL;

    double* max = a;

    for (int i = 1; i < size; i++) {
        if (*(a + i) > *max) {
            max = a + i;
        }
    }

    return max;
}
