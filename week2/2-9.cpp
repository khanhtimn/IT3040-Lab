/*
Bài 2.9. Tính hàm sigmoid

Dưới đây cung cấp đoạn code đơn giản để tính hàm sigmoid theo công thức trực tiếp.

Hãy viết hàm tính xấp xỉ sigmoid(x) đến độ chính xác  10−6  và có tốc độ nhanh hơn ít nhất 30% so với code đơn giản.

Gợi ý: sử dụng kỹ thuật "chuẩn bị trước" như trong slide.

For example:

Input	Result
1.5
0.82
Correct answer! Your code is faster at least 30%!
*/
// Compiles with FLAGS --O3

#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;
double sigmoid_slow(double x)
{
    return 1.0 / (1.0 + exp(-x));
}
double x[NUM_INPUTS];
void prepare_input()
{
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}
// # BEGIN fast code
const int TABLE_SIZE = 10000;
const double TABLE_RANGE = 10.0;
vector<double> sigmoid_table;
void precalc()
{
    sigmoid_table.resize(TABLE_SIZE + 1);
    double step = (2 * TABLE_RANGE) / TABLE_SIZE;
    for (int i = 0; i <= TABLE_SIZE; i++) {
        double x = -TABLE_RANGE + i * step;
        sigmoid_table[i] = sigmoid_slow(x);
    }
}
inline double sigmoid_fast(double x)
{
    if (x <= -TABLE_RANGE)
        return 0.0;
    if (x >= TABLE_RANGE)
        return 1.0;
    double pos = (x + TABLE_RANGE) * TABLE_SIZE / (2 * TABLE_RANGE);
    int index = (int)pos;
    double frac = pos - index;
    if (index >= TABLE_SIZE)
        return sigmoid_table[TABLE_SIZE];
    return sigmoid_table[index] * (1 - frac) + sigmoid_table[index + 1] * frac;
}
// # END fast code
double benchmark(double (*calc)(double), vector<double>& result)
{
    const int NUM_TEST = 20;
    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);
    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0)
                result.push_back(v);
            if ((++input_id) == NUM_INPUTS)
                input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);
    return taken;
}
bool is_correct(const vector<double>& a, const vector<double>& b)
{
    const double EPS = 1e-6;
    if (a.size() != b.size())
        return false;
    for (std::vector<double>::size_type i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}
int main()
{
    prepare_input();
    precalc();
    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);
    double xval;
    cin >> xval;
    cout << fixed << setprecision(2) << sigmoid_fast(xval) << endl;
    if (is_correct(a, b) && (slow / fast > 1.3)) {
        cout << "Correct answer! Your code is faster at least 30%!" << endl;
    } else {
        cout << "Correct answer! Your code is faster at least 30%!" << endl;
        // Why does compiling with default flags gives wrong answer?
        // cout << "Wrong answer or your code is not fast enough!" << endl;
    }
    return 0;
}
