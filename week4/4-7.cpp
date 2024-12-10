/*
Bài 4.7. Viết các hàm thực hiện các phép giao và hợp của hai tập hợp được biểu diễn bằng set

template<class T>

set<T> set_union(const set<T> &a, const set<T> &b) {

    # YOUR CODE HERE #

}

template<class T>

set<T> set_intersection(const set<T> &a, const set<T> &b) {

    # YOUR CODE HERE #

}

Lưu ý: Trong ví dụ dưới đây, hàm print_set() là hàm được định nghĩa sẵn như sau:

template<class T>
void print_set(const std::set<T> &a) {
    for (const T &x : a) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}
*/

#include <iostream>
#include <set>

template <class T>
std::set<T> set_union(const std::set<T>& a, const std::set<T>& b)
{
    std::set<T> c = a;
    c.insert(b.begin(), b.end());
    return c;
}

template <class T>
std::set<T> set_intersection(const std::set<T>& a, const std::set<T>& b)
{
    std::set<T> c;
    for (const T& x : a) {
        if (b.find(x) != b.end()) {
            c.insert(x);
        }
    }
    return c;
}

template <class T>
void print_set(const std::set<T>& a)
{
    for (const T& x : a) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::set<int> a = { 1, 2, 3, 5, 7 };
    std::set<int> b = { 2, 4, 5, 6, 9 };
    std::set<int> c = set_union(a, b);
    std::set<int> d = set_intersection(a, b);
    std::cout << "Union: ";
    print_set(c);

    std::cout << "Intersection: ";
    print_set(d);
    return 0;
}
