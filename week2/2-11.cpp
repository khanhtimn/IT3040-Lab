/*
Tính tích hai đa thức
Cho 2 đa thức A(x) và B(x) tương ứng có bậc  N và  M
Hãy tính ma trận tích C(x) = A(x) * B(x) có bậc  N+M−1

Input: Gồm 2 dòng biểu diễn các đa thức A(x) và B(x), mỗi dòng

Số đầu tiên  N là bậc của đa thức;
N+1 số nguyên tiếp theo, số thứ i là hệ số của x^(i−1).
Output: Một số nguyên duy nhất là XOR của các hệ số của đa thức C(x).

Ví dụ:

Input:
3 83 86 77 15
4 93 35 86 92 49

Output:
20731

Giải thích: các hệ số của đa thức kết quả lần lượt là 7719, 10903, 17309, 19122, 19126, 12588, 5153, 735.

Giới hạn:

Các hệ số của các đa thức đầu vào có trị tuyệt đối nhỏ hơn 100.
Có 5 tests, test thứ i có bậc của các đa thức đầu vào không quá 10^i
*/

#include "complex"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const double PI = acos(-1);

// Reference: https://faculty.sites.iastate.edu/jia/files/inline-files/polymultiply.pdf
void FFT(vector<complex<double>>& a, bool inv)
{
    unsigned int n = a.size();

    if (n == 1) {
        return;
    }

    vector<complex<double>> a_even(n / 2);
    vector<complex<double>> a_odd(n / 2);

    for (unsigned int i = 0; 2 * i < n; i++) {
        a_even[i] = a[2 * i];
        a_odd[i] = a[2 * i + 1];
    }

    FFT(a_even, inv);
    FFT(a_odd, inv);

    double ang = 2 * PI / n * (inv ? -1 : 1);
    complex<double> w(1);
    complex<double> wn(cos(ang), sin(ang));

    for (unsigned int i = 0; 2 * i < n; i++) {
        a[i] = a_even[i] + w * a_odd[i];
        a[i + n / 2] = a_even[i] - w * a_odd[i];
        if (inv) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<int> multiply(vector<int> const& A, vector<int> const& B)
{
    vector<complex<double>> fa(A.begin(), A.end()), fb(B.begin(), B.end());

    unsigned int n = 1;

    while (n < A.size() + B.size())
        n <<= 1;

    fa.resize(n);
    fb.resize(n);

    FFT(fa, false);
    FFT(fb, false);

    for (unsigned int i = 0; i < n; i++)
        fa[i] *= fb[i];

    FFT(fa, true);

    vector<int> result(n);

    for (unsigned int i = 0; i < n; i++)
        result[i] = round(fa[i].real());

    return result;
}

int main()
{
    int N1;
    cin >> N1;
    vector<int> A(N1 + 1);
    for (int i = 0; i <= N1; i++) {
        cin >> A[i];
    }

    int N2;
    cin >> N2;
    vector<int> B(N2 + 1);
    for (int i = 0; i <= N2; i++) {
        cin >> B[i];
    }

    vector<int> C = multiply(A, B);

    int result = 0;
    for (unsigned int i = 0; i < C.size(); i++) {
        result ^= C[i];
    }

    cout << result << endl;

    return 0;
}
