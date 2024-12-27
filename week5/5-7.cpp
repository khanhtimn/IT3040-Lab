/*
Sau đại dịch, thầy trò Đường Tăng muốn xin tiền của các nhà giàu để chia cho các nhà nghèo.
Họ sẽ vào n thôn, thôn thứ i có ki nhà. Mỗi thôn họ sẽ quyết định xin tiền hay cho tiền, phụ thuộc vào đánh giá của họ về mức độ giàu nghèo ở đây.
Nếu thôn i giàu, họ sẽ đi từng nhà trong số nhà này và xin ai,j tiền của nhà thứ j.
Nếu thôn i nghèo, họ sẽ đi từng nhà trong số ki nhà này và phát ai,j tiền cho nhà thứ j.
Hãy tính số tiền ít nhất họ phải mang theo để đảm bảo có thể phát đủ cho người nghèo (tức số tiền luôn không bị âm)
Mã nguồn sau giải quyết bài toán đó, hãy tinh chỉnh nó để tăng hiệu suất chương trình.
*/

#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    long long sum = 0;
    long long minNeeded = 0;

    while (n--) {
        int houses, action;
        std::cin >> houses >> action;

        while (houses--) {
            int money;
            std::cin >> money;
            sum += action * money;
            minNeeded = std::max(minNeeded, -sum);
        }
    }

    std::cout << minNeeded;
    return 0;
}
