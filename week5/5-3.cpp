/*
H. PARENTHESES
- time limit per test: 1 second
- memory limit per test: 256 megabytes

The input file consists of several datasets.
The first line of the input file contains the number of datasets which is a positive integer T and is not greater than 1000.
Each of T following lines describes a parentheses expression including: '(',')','[',']','{','}'.

Output
For each dataset, write in one line 1 or 0 if the expression is correct or not respectively.

Example
Input
2
([]())
()()()[}
Output
1
0
*/

#include <iostream>
using namespace std;
#include <stack>
int par(string str)
{
    int a = str.length();
    stack<char> S;
    char x;
    for (int i = 0; i < a; i++) {
        x = str[i];
        if (x == '(' || x == '[' || x == '{') {
            S.push(x);
        } else {
            if (x == ')') {
                if (S.top() == '(') {
                    S.pop();
                } else
                    return 0;
            } else if (x == ']') {
                if (S.top() == '[') {
                    S.pop();
                } else
                    return 0;
            } else if (x == '}') {
                if (S.top() == '{') {
                    S.pop();
                } else
                    return 0;
            }
        }
    }
    if (S.empty()) {
        return 1;
    } else
        return 0;
}
int main()
{
    int n;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        cout << par(str) << endl;
    }

    return 0;
}
