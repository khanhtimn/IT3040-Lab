/*
Bài 4.4. Cho hai std::vector, hãy xóa hết các phần tử chẵn,
sắp xếp giảm dần các số trong cả 2 vector và trộn lại thành một vector cũng được sắp xếp giảm dần.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void print_vector(const std::vector<int>& a)
{
    for (int v : a)
        std::cout << v << " ";
    std::cout << std::endl;
}

void delete_even(std::vector<int>& a)
{
    a.erase(std::remove_if(a.begin(), a.end(), [](int x) {
        return x % 2 == 0;
    }),
        a.end());
}

void sort_decrease(std::vector<int>& a)
{
    std::sort(a.rbegin(), a.rend());
}

std::vector<int> merge_vectors(const std::vector<int>& a, const std::vector<int>& b)
{
    std::vector<int> c;
    merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(c), std::greater<int>());
    return c;
}

int main()
{
    int m, n, u;
    std::vector<int> a, b;
    std::cin >> m >> n;
    for (int i = 0; i < m; i++) {
        std::cin >> u;
        a.push_back(u);
    }
    for (int i = 0; i < n; i++) {
        std::cin >> u;
        b.push_back(u);
    }
    delete_even(a);
    std::cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    std::cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    std::cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    std::cout << "Decreasingly sorted b: ";
    print_vector(b);

    std::vector<int> c = merge_vectors(a, b);
    std::cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
