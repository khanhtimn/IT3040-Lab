/*
Big Integer
Số nguyên lớn là các số nguyên có giá trị rất lớn và không thể biểu diễn bằng các kiểu dữ liệu nguyên cơ bản.
Để biểu diễn số nguyên lớn, ta có thể dùng kiểu struct như sau:

struct bigNum{
     char sign;
     char num[101];
};

Nhiệm vụ các bạn là đa năng hóa các toán tử để thực hiện các phép toán số học với kiểu dữ liệu số nguyên lớn vừa định nghĩa ở trên.
Input: Dữ liệu vào gồm hai dòng mô tả hai số nguyên lớn a và b, mỗi dòng chứa 1 chuỗi ký tự mô tả 1 số nguyên lớn không vượt quá 10^100.
Chữ số đầu của mỗi chuỗi ký tự sẽ thể hiện dấu của số đó: 0 là âm, 1 là dương. Các chữ số sau thể hiện giá trị của số đó.
Output: In ra giá trị của biểu thức ab − 3a + 4b. Kết quả in ra một số nguyên lớn dưới dạng chuỗi ký tự có định dạng như mô tả trong dữ liệu vào.
Ví dụ:
Input:
0121807015
1347227347
Output:
042294724910108772
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct bigNum {
    char sign;
    string num;
};

void normalize(bigNum& a)
{
    while (a.num.size() > 1 && a.num[0] == '0') {
        a.num.erase(0, 1);
    }
    if (a.num.empty()) {
        a.num = "0";
        a.sign = '1';
    }
}

int compare(const string& a, const string& b)
{
    if (a.length() != b.length())
        return a.length() - b.length();
    return a.compare(b);
}

string add(const string& a, const string& b)
{
    string result;
    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0)
            sum += a[i--] - '0';
        if (j >= 0)
            sum += b[j--] - '0';
        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
    }
    return result;
}

string subtract(const string& a, const string& b)
{
    string result;
    int borrow = 0;
    string num1 = a, num2 = b;
    while (num2.length() < num1.length())
        num2 = "0" + num2;

    for (int i = num1.length() - 1; i >= 0; i--) {
        int diff = (num1[i] - '0') - (num2[i] - '0') - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result = char(diff + '0') + result;
    }
    while (result.size() > 1 && result[0] == '0') {
        result.erase(0, 1);
    }
    return result;
}

string multiply(const string& a, const string& b)
{
    vector<int> result(a.length() + b.length(), 0);

    for (int i = a.length() - 1; i >= 0; i--) {
        for (int j = b.length() - 1; j >= 0; j--) {
            result[i + j + 1] += (a[i] - '0') * (b[j] - '0');
        }
    }

    for (int i = result.size() - 1; i > 0; i--) {
        result[i - 1] += result[i] / 10;
        result[i] %= 10;
    }

    string s;
    unsigned int i = 0;
    while (i < result.size() - 1 && result[i] == 0)
        i++;
    while (i < result.size())
        s += result[i++] + '0';
    return s;
}

bigNum operator+(const bigNum& a, const bigNum& b)
{
    bigNum result;
    if (a.sign == b.sign) {
        result.sign = a.sign;
        result.num = add(a.num, b.num);
    } else {
        int comp = compare(a.num, b.num);
        if (comp >= 0) {
            result.sign = a.sign;
            result.num = subtract(a.num, b.num);
        } else {
            result.sign = b.sign;
            result.num = subtract(b.num, a.num);
        }
    }
    normalize(result);
    return result;
}

bigNum operator-(const bigNum& a, const bigNum& b)
{
    bigNum neg_b = b;
    neg_b.sign = (b.sign == '1') ? '0' : '1';
    return a + neg_b;
}

bigNum operator*(const bigNum& a, const bigNum& b)
{
    bigNum result;
    result.sign = (a.sign == b.sign) ? '1' : '0';
    result.num = multiply(a.num, b.num);
    normalize(result);
    return result;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    bigNum a { s1[0], s1.substr(1) };
    bigNum b { s2[0], s2.substr(1) };

    bigNum result = (a * b) - (a + a + a) + (b + b + b + b);
    cout << result.sign << result.num << endl;

    return 0;
}
