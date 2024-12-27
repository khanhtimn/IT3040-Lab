#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int& x : a)
        std::cin >> x;
    printf("Done input\n");
    std::vector<int> f(n);
    for (int i = 0; i < f.size(); ++i) {
        int& ans = f[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i])
                ans = std::max(ans, f[j] + 1);
        }
        printf("i=%d, a=%d, f=%d\n", i, a[i], f[i]);
    }
    std::cout << *max_element(f.begin(), f.end());
}
