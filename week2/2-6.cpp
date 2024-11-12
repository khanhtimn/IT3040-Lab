/*
Bài 2.6. Giả thuyết Collatz: bắt đầu từ số dương n bất kỳ, nếu n chẵn thì chia 2, nếu lẻ thì nhân 3 cộng 1, giả thuyết cho rằng ta luôn đi đến

Hãy viết chương trình mô phỏng lại quá trình biến đổi để kiếm chứng giả thuyết với giá trị của n nhập từ bàn phím.

For example:

Input	Result
19
n=19
n=58
n=29
n=88
n=44
n=22
n=11
n=34
n=17
n=52
n=26
n=13
n=40
n=20
n=10
n=5
n=16
n=8
n=4
n=2
n=1
*/

#include <iostream>

void print(int n)
{
    std::cout << "n=" << n << std::endl;
}

int mul3plus1(int n)
{
    return n * 3 + 1;
}

int div2(int n)
{
    return n / 2;
}

void simulate(int n,
    int (*odd)(int),
    int (*even)(int),
    void (*output)(int))
{
    (*output)(n);
    if (n == 1)
        return;
    if (n % 2 == 0) {
        n = (*even)(n);
    } else {
        n = (*odd)(n);
    }
    simulate(n, odd, even, output);
}

int main()
{
    int (*odd)(int) = mul3plus1;
    int (*even)(int) = div2;

    int n;
    std::cin >> n;
    simulate(n, odd, even, print);

    return 0;
}
