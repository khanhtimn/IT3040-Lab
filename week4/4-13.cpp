/*
Cho một xâu nhị phân độ dài n. Hãy viết chương trình đếm số lượng xâu con chứa số ký tự 0 và số ký tự 1 bằng nhau.
Dữ liệu vào:
Một dòng duy nhất chứa một xâu nhị phân độ dài n (1≤n≤106).
Kết quả:
Ghi ra một số nguyên duy nhất là số lượng xâu con có số ký tự 0 và số ký tự 1 bằng nhau.
Ví dụ:
Dữ liệu vào:
1001011
Kết quả:
8
Giải thích: Trong ví dụ trên có 8 xâu con thỏa mãn là 10, 01, 10, 01, 1001, 0101, 100101, 001011
*/

#include <iostream>
#include <map>

inline int calc(int v)
{
    return v * (v - 1) / 2;
}

int main()
{
    std::string str;
    std::cin >> str;

    std::map<int, int> m;
    std::map<int, int>::iterator it;
    int difference = 0;

    for (char c : str) {
        if (c == '0')
            difference--;
        else
            difference++;

        it = m.find(difference);
        if (it != m.end()) {
            it->second += 1;
        } else {
            m.insert({ difference, 1 });
        }
    }

    int res = 0; // result
    for (it = m.begin(); it != m.end(); ++it) {
        res += calc(it->second);
        if (it->first == 0)
            res += it->second;
    }

    std::cout << res;
    return 0;
}
