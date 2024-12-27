#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

double distance(pair<int, int> p1, pair<int, int> p2)
{
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

void findClosestPair(vector<pair<int, int>>& points, int& idx1, int& idx2, double& minDist)
{
    minDist = 1e18;
    for (unsigned int i = 0; i < points.size(); i++) {
        for (unsigned int j = i + 1; j < points.size(); j++) {
            double dist = distance(points[i], points[j]);
            if (dist < minDist) {
                minDist = dist;
                idx1 = i;
                idx2 = j;
            }
        }
    }
}

int main()
{
    srand(time(0));

    ofstream input("input.txt");
    int n = 5;
    input << n << endl;

    vector<pair<int, int>> points;
    points.push_back({ 0, 0 });
    points.push_back({ 0, 1 });
    points.push_back({ 100, 45 });
    points.push_back({ 2, 3 });
    points.push_back({ 9, 9 });

    for (auto p : points) {
        input << p.first << " " << p.second << endl;
    }
    input.close();

    int correctIdx1, correctIdx2;
    double correctDist;
    findClosestPair(points, correctIdx1, correctIdx2, correctDist);

    system("5-4.exe < input.txt > output.txt");

    ifstream output("output.txt");
    int resultIdx1, resultIdx2;
    double resultDist;
    output >> resultIdx1 >> resultIdx2 >> resultDist;
    output.close();

    cout << "Test case:" << endl;
    cout << "Input:" << endl;
    cout << n << endl;
    for (auto p : points) {
        cout << p.first << " " << p.second << endl;
    }

    cout << "\nRight answer: " << endl;
    cout << correctIdx1 << " " << correctIdx2 << " " << fixed << setprecision(6) << correctDist << endl;

    cout << "\nAnswer of 5-4: " << endl;
    cout << resultIdx1 << " " << resultIdx2 << " " << fixed << setprecision(6) << resultDist << endl;

    if (abs(correctDist - resultDist) > 1e-6 || (correctIdx1 != resultIdx1 && correctIdx1 != resultIdx2) || (correctIdx2 != resultIdx1 && correctIdx2 != resultIdx2)) {
        cout << "\nThere is a wrong test case!" << endl;
    } else {
        cout << "\nEverything ok!" << endl;
    }

    return 0;
}
