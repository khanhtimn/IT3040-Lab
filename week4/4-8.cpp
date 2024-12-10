/*
Bài 4.8. Viết các hàm thực hiện các phép giao và hợp của hai tập hợp mờ được biểu diễn bằng map.

Trong đó mỗi phần tử được gán cho một số thực trong đoạn [0..1] biểu thị độ thuộc của phần tử trong tập hợp, với độ thuộc bằng 1 nghĩa là phần tử chắc chắn thuộc vào tập hợp và ngược lại độ thuộc bằng 0 nghĩa là phần tử chắc chắn không thuộc trong tập hợp.

Phép giao và hợp của 2 tập hợp được thực hiện trên các cặp phần tử bằng nhau của 2 tập hợp, với độ thuộc mới được tính bằng phép toán min và max của hai độ thuộc.

template<class T>

map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {

    # YOUR CODE HERE #

}

template<class T>

map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {

    # YOUR CODE HERE #

}

Lưu ý: Trong ví dụ dưới đây, hàm print_fuzzy_set() được định nghĩa sẵn như sau:

template<class T>
void print_fuzzy_set(const map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    cout << endl;
}
*/

#include <iostream>
#include <map>

template <class T>
std::map<T, double> fuzzy_set_union(const std::map<T, double>& a, const std::map<T, double>& b)
{
    std::map<T, double> c = a;
    for (const auto& e : b) {
        if (c.count(e.first)) {
            c[e.first] = std::max(c[e.first], e.second);
        } else {
            c.insert(e);
        }
    }
    return c;
}

template <class T>
std::map<T, double> fuzzy_set_intersection(const std::map<T, double>& a, const std::map<T, double>& b)
{
    std::map<T, double> c;
    for (const auto& x : a) {
        const auto it = b.find(x.first);
        if (it != b.end()) {
            c[x.first] = std::min(x.second, it->second);
        }
    }
    return c;
}

template <class T>
void print_fuzzy_set(const std::map<T, double>& a)
{
    std::cout << "{ ";
    for (const auto& x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    std::cout << "}";
    std::cout << std::endl;
}

int main()
{
    std::map<int, double> a = { { 1, 0.2 }, { 2, 0.5 }, { 3, 1 }, { 4, 0.6 }, { 5, 0.7 } };
    std::map<int, double> b = { { 1, 0.5 }, { 2, 0.4 }, { 4, 0.9 }, { 5, 0.4 }, { 6, 1 } };
    std::cout << "A = ";
    print_fuzzy_set(a);
    std::cout << "B = ";
    print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: ";
    print_fuzzy_set(c);
    std::cout << "Intersection: ";
    print_fuzzy_set(d);
}
