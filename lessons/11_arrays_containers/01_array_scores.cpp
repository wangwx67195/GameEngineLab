#include <iostream>
#include <cstddef>
#include <array>
using std::cout;

int main() {
    std::array <int, 5> scores = {61, 75, 90, 85, 100};
    int sum = 0;
    int max = scores[0];
    for (std::size_t i = 0; i < scores.size(); ++i) {
        cout << "index = " << i << ", score = " << scores[i] << '\n';
        sum += scores[i];
        if (scores[i] > max) {
            max = scores[i];
        }
    }
    cout << "sum = " << sum << '\n';
    double mean = double(sum) / scores.size();
    cout << "mean = " << mean << '\n';
    cout << "max = " << max << '\n';


    return 0;
}



