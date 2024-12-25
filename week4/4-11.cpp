/*
Bức tường bao quanh một lâu đài nọ được cấu thành từ n đoạn tường được đánh số từ 1 đến n.
Quân giặc lên kế hoạch tấn công lâu đài bằng cách gửi ai tên giặc đánh vào đoạn tường thứ i.Để bảo vệ lâu đài có tất cả s lính.
Do các đoạn tường có chất lượng khác nhau nên khả năng bảo vệ tại các đoạn tường cũng khác nhau.
Cụ thể tại đoạn tường thứ i, mỗi lính có thể đẩy lùi tấn công của ki tên giặc.
Giả sử đoạn tường thứ i có xi lính. Khi đó nếu số tên giặc không vượt quá xi × ki thì không có tên giặc nào lọt vào được qua đoạn tường này.
Ngược lại sẽ có ai − xi × ki tên giặc lọt vào lâu đài qua đoạn tường này.
Yêu cầu hãy viết chương trình phân bố lính đứng ở các đoạn tường sao cho tổng số lính là s và tổng số lượng tên giặc lọt vào lâu đài là nhỏ nhất.
Dữ liệu vào:
Dòng thứ nhất chứa các số nguyên n và s (1≤n≤100000;1≤s≤109).
n dòng tiếp theo chứa hai số nguyên ai và ki lần lượt là số tên giặc tấn công đoạn tường thứ i và khả năng chống trả của một lính ở đoạn tường thứ i (1≤ai,ki≤109).
Kết quả:
Ghi ra một số nguyên duy nhất là số lượng tên giặc tối thiểu có thể lọt vào lâu đài.
Ví dụ:
Dữ liệu vào:
3 3
4 2
1 1
10 8
Kết quả:
3
*/

#include <iostream>
#include <queue>
#include <vector>

struct Data {
    int ai;
    int ki;

    Data(int ai, int ki)
    {
        this->ai = ai;
        this->ki = ki;
    }
};

struct compare {
    bool operator()(Data a, Data b)
    {
        int ra, rb;

        if (a.ai <= a.ki)
            ra = a.ai;
        else
            ra = a.ki;

        if (b.ai <= b.ki)
            rb = b.ai;
        else
            rb = b.ki;

        return ra < rb;
    }
};

int n, s, kill_enemy, total_enemy;
std::priority_queue<Data, std::vector<Data>, compare> p_q;

void input()
{
    std::cin >> n >> s;
    kill_enemy = 0;
    total_enemy = 0;
    for (int i = 0; i < n; i++) {
        int tmp1, tmp2;
        std::cin >> tmp1 >> tmp2;
        total_enemy += tmp1;
        p_q.push(Data(tmp1, tmp2));
    }
}

void solve()
{
    while (!p_q.empty() && s > 0) {
        Data inf = p_q.top();
        p_q.pop();

        if (inf.ai <= inf.ki) {
            kill_enemy += inf.ai;
        } else {
            int nenemy = inf.ai - inf.ki;
            p_q.push(Data(nenemy, inf.ki));
            kill_enemy += inf.ki;
        }

        s -= 1;
    }
}

int calc_enemy()
{
    return total_enemy - kill_enemy;
}

int main()
{
    input();
    solve();
    std::cout << calc_enemy();
    return 0;
}
