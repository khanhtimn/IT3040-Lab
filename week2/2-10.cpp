#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>

using namespace std;

const int N = 128;
const int BLOCK_SIZE = 32;

struct Matrix {
    unsigned int mat[N][N];

    Matrix()
    {
        memset(mat, 0, sizeof mat);
    }
};

bool operator==(const Matrix& a, const Matrix& b)
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (a.mat[i][j] != b.mat[i][j])
                return false;
        }
    }
    return true;
}

Matrix multiply_naive(const Matrix& a, const Matrix& b)
{
    Matrix c;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
            }
        }
    }
    return c;
}

Matrix multiply_fast(const Matrix& a, const Matrix& b)
{
    Matrix c;

    for (int i0 = 0; i0 < N; i0 += BLOCK_SIZE) {
        for (int j0 = 0; j0 < N; j0 += BLOCK_SIZE) {
            for (int k0 = 0; k0 < N; k0 += BLOCK_SIZE) {

                for (int i = i0; i < min(i0 + BLOCK_SIZE, N); ++i) {
                    for (int j = j0; j < min(j0 + BLOCK_SIZE, N); ++j) {
                        unsigned int sum = c.mat[i][j];
                        for (int k = k0; k < min(k0 + BLOCK_SIZE, N); ++k) {
                            sum += a.mat[i][k] * b.mat[k][j];
                        }
                        c.mat[i][j] = sum;
                    }
                }
            }
        }
    }
    return c;
}

Matrix gen_random_matrix()
{
    Matrix a;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            a.mat[i][j] = rand();
        }
    }
    return a;
}

Matrix base;

double benchmark(Matrix (*multiply)(const Matrix&, const Matrix&), Matrix& result)
{
    const int NUM_TEST = 10;
    const int NUM_ITER = 64;

    Matrix a = base;
    result = a;

    double taken = 0;
    for (int t = 0; t < NUM_TEST; ++t) {
        clock_t start = clock();
        for (int i = 0; i < NUM_ITER; ++i) {
            a = multiply(a, result);
            result = multiply(result, a);
        }
        clock_t finish = clock();
        taken += (double)(finish - start);
    }
    taken /= NUM_TEST;

    cout << "Time: " << fixed << setprecision(9) << taken / CLOCKS_PER_SEC << endl;
    return taken;
}

int main()
{
    base = gen_random_matrix();

    Matrix a, b;
    cout << "Slow version" << endl;
    double slow = benchmark(multiply_naive, a);
    cout << "Fast version" << endl;
    double fast = benchmark(multiply_fast, b);

    if (a == b) {
        cout << "Correct answer! Your code is " << fixed << setprecision(2) << slow / fast * 100.0 << " faster" << endl;
    } else {
        cout << "Wrong answer!" << endl;
    }
    return 0;
}
