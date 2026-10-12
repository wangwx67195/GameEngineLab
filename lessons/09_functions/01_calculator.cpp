#include <iostream>
#include <cstdio>

int add(int a, int b) {
    int result = a + b;
    return result;
}

double square(double value) {
    double result = value * value;
    return result;
}

double maximum(double a, double b) {
    double result;
    
    if (a > b) {
        result = a;
    }
    else {
        result = b;
    }

    return result;
}

int main() {
    int sum_0 = add(3, 5);
    int sum_1 = add(-3, 5);

    double square_0 = square(2.5);
    double square_1 = square(-3.0);

    double maximum_0 = maximum(-2.0, -5.0);
    double maximum_1 = maximum(4.0, 4.0);

    std::cout << "sum_0" << sum_0 << ", sum_1" << sum_1 << '\n';
    std::cout << "square_0" << square_0 << ", square_1" << square_1 << '\n';
    std::cout << "maximum_0" << maximum_0 << ", maximum_1" << maximum_1 << '\n';

    return 0;
}