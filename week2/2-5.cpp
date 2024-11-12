/*
Bài 2.5. Viết các toán tử tính tổng, hiệu, tích và thương của hai số phức

For example:

Input	Result
3.2 4
1.1 -1
(3.2+4i) + (1.1-1i) = (4.3+3i)
(3.2+4i) - (1.1-1i) = (2.1+5i)
(3.2+4i) * (1.1-1i) = (7.5+1.2i)
(3.2+4i) / (1.1-1i) = (-0.22+3.4i)
*/

#include <cmath>
#include <iomanip>
#include <iostream>
#include <ostream>

using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex operator+(Complex a, Complex b)
{
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex operator-(Complex a, Complex b)
{
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex operator*(Complex a, Complex b)
{
    Complex result;
    result.real = a.real * b.real - a.imag * b.imag;
    result.imag = a.real * b.imag + a.imag * b.real;
    return result;
}

Complex operator/(Complex a, Complex b)
{
    Complex result;
    double denominator = b.real * b.real + b.imag * b.imag;
    result.real = (a.real * b.real + a.imag * b.imag) / denominator;
    result.imag = (a.imag * b.real - a.real * b.imag) / denominator;
    return result;
}

ostream& operator<<(ostream& out, const Complex& a)
{
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main()
{
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;

    Complex a { real_a, img_a };
    Complex b { real_b, img_b };

    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;

    return 0;
}
