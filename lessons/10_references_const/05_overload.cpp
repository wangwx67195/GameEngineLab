#include <iostream>
using std::cout;

int maximum(int a, int b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

double maximum(double a, double b) {
    if (a > b) {
        return a;
    }
    else {
        return b;
    }
}

int main() {
    int max1 = maximum(3, 7);
    int max2 = maximum(-2, -5);
    int max3 = maximum(4, 4);
    double max4 = maximum(2.5, 7.2);
    double max5 = maximum(-2.5, -5.0);

    cout << max1 << '\n' << max2 << '\n' << max3 << '\n' << max4 << '\n' << max5;

    // int max_err = maximum(3, 7.5);

    return 0;
}



