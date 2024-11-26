/*
Một y tá cần lập lịch làm việc trong N ngày, mỗi ngày chỉ có thể là làm việc hay nghỉ ngơi.
Một lịch làm việc là tốt nếu không có hai ngày nghỉ nào liên tiếp và mọi chuỗi ngày tối đại làm việc liên tiếp đều có số ngày thuộc đoạn [K1,K2].
Hãy liệt kê tất cả các cách lập lịch tốt, với mỗi lịch in ra trên một dòng một xâu nhị phân độ dài n
với bit 0/1 tương ứng là nghỉ/làm việc. Các xâu phải được in ra theo thứ tự từ điển.

Dữ liệu vào:

Ghi 3 số nguyên  N,K1,K2 (N≤200, K1<K2≤70)

Kết quả:

Ghi danh sách các lịch tìm được theo thứ tự từ điển

Ví dụ:

Dữ liệu mẫu:

6 2 3

Kết quả mẫu:

011011
110110
110111
111011
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, K1, K2;
string schedule;
vector<string> results;

bool isValid()
{
    int len = schedule.length();

    for (int i = 0; i < len - 1; i++) {
        if (schedule[i] == '0' && schedule[i + 1] == '0')
            return false;
    }

    int count = 0;
    for (int i = 0; i < len; i++) {
        if (schedule[i] == '1') {
            count++;
            if (count > K2)
                return false;
        } else {
            if (count > 0 && count < K1)
                return false;
            count = 0;
        }
    }
    if (count > 0 && count < K1)
        return false;

    return true;
}

void generate(int pos)
{
    if (pos == N) {
        if (isValid()) {
            results.push_back(schedule);
        }
        return;
    }

    schedule[pos] = '0';
    if (pos == 0 || (pos > 0 && schedule[pos - 1] != '0')) {
        generate(pos + 1);
    }

    schedule[pos] = '1';
    int count = 0;
    for (int i = pos; i >= 0 && schedule[i] == '1'; i--) {
        count++;
    }
    if (count <= K2) {
        generate(pos + 1);
    }
}

int main()
{
    cin >> N >> K1 >> K2;
    schedule = string(N, '0');

    generate(0);

    for (const string& result : results) {
        cout << result << endl;
    }

    return 0;
}
