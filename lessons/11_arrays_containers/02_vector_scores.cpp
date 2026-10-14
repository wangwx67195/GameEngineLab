#include <iostream>
#include <vector>
#include <cstddef>
#include <array>
using std::cout;

int main() {
    std::vector<int> scores;
    // scores.push_back({61, 75, 90, 85, 100});
    // scores.push_back(61);
    // scores.push_back(75);
    // scores.push_back(90);
    // scores.push_back(85);
    // scores.push_back(100);

    // scores.push_back(-8);
    // scores.push_back(-3);
    // scores.push_back(-12);

    // scores.push_back(42);

    if (scores.size() == 0) {
        cout << "没有成绩" << '\n';
        return 0;
    }

    cout << "scores.size() = " << scores.size() << '\n';
    cout << "scores.empty() = " << scores.empty() << '\n';
    int sum = 0;
    int max = scores[0];

    for (int score : scores) {

        cout << "score = " << score << '\n';
        sum += score;
        if (max < score) {
            max = score;
        }
    }
    double mean = double(sum) / scores.size();
    cout << "sum = " << sum << '\n';
    cout << "mean = " << mean << '\n';
    cout << "max = " << max << '\n';

    sum = 0;
    max = scores[0];
    for (int& score : scores) {
        score += 5;
    }
    for (int score : scores) {

        cout << "score = " << score << '\n';
        sum += score;
        if (max < score) {
            max = score;
        }
    }
    mean = double(sum) / scores.size();
    cout << "sum = " << sum << '\n';
    cout << "mean = " << mean << '\n';
    cout << "max = " << max << '\n';

    return 0;
}