/*
Một lớp có sinh viên. Sinh viên thứ có điểm tổng kết là theo thang điểm 10.
Để đánh giá chất lượng dạy học, giảng viên muốn biết có bao nhiêu bạn đạt điểm A, B, C, D, F
Mã nguồn sau giải quyết bài toán đó, hãy tinh chỉnh nó để tăng hiệu suất chương trình.
*/

#include <iostream>

char getGrade(double score)
{
    if (score >= 8.5)
        return 'A';
    if (score >= 7.0)
        return 'B';
    if (score >= 5.5)
        return 'C';
    if (score >= 4.0)
        return 'D';
    return 'F';
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int grades[5] = { 0 };

    while (n--) {
        double score;
        std::cin >> score;
        char grade = getGrade(score);
        grades[grade - 'A']++;
    }

    for (int i = 0; i < 5; i++) {
        // A - B - C - D - F
        std::cout << grades[i] << (i < 4 ? " " : "\n");
    }

    return 0;
}
