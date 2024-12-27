/*
G. 05. MARBLE
- time limit per test: 1 second
- memory limit per test: 256 megabytes
Phong là một nhà điêu khắc, ông có một tấm đá cẩm thạch hình chữ nhật kích thước W×H.
Ông ta muốn cắt tấm đá thành các miếng hình chữ nhật kích thước W1×H1,W2×H2,…,WN×HN.
Ông ta muốn cắt đến tối đa các mẫu kích thước có thể.
Tấm đá có những vân đá cho nên không thể xoay khi sử dụng, có nghĩa là không thể cắt ra miếng B×A thay cho miếng A×B trừ khi A=B.
Các miếng phải được cắt tại các điểm nguyên trên hàng cột và mỗi nhát cắt phải cắt đến hết hàng hoặc hết cột.
Sau khi cắt sẽ còn lại những mẩu đá còn thừa bỏ đi, nghĩa là những mẩu đá không thể cắt thành miếng kích thước cho trước nào.

Yêu cầu: Hãy tìm cách cắt sao cho còn ít nhất diện tích đá thừa bỏ đi.
Input
Dòng đầu tiên chứa hai số nguyên: W và H.
Dòng thứ hai chứa một số nguyên N.
N dòng tiếp theo mỗi dòng chứa hai số nguyên Wi và Hi (1≤i≤N).

Output
Kết quả ghi ra duy nhất một số nguyên là tổng diện tích nhỏ nhất các miếng thừa bỏ đi.

Scoring
1≤W≤600,1≤H≤600,0<N≤200,1≤Wi≤W, and 1≤Hi≤H.
Có 50% số test ứng với W≤20,H≤20 và N≤5.

Example
Input
21 11
4
10 4
6 2
7 5
15 10

Output
10
*/

#include <algorithm>
#include <iostream>
#include <vector>

int w, h;
std::vector<std::vector<int>> table;

void init()
{
    table.assign(h + 1, std::vector<int>(w + 1, 0));
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            table[i][j] = i * j;
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> w >> h;
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> pieces(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> pieces[i].first >> pieces[i].second;
    }

    init();

    for (const auto& piece : pieces) {
        int pw = piece.first, ph = piece.second;
        if (pw <= w && ph <= h) {
            table[ph][pw] = 0;
        }
    }

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            int minWaste = table[i][j];

            for (int k = 1; k < i; ++k) {
                minWaste = std::min(minWaste, table[k][j] + table[i - k][j]);
            }

            for (int k = 1; k < j; ++k) {
                minWaste = std::min(minWaste, table[i][k] + table[i][j - k]);
            }

            table[i][j] = minWaste;
        }
    }

    std::cout << table[h][w] << '\n';
    return 0;
}
