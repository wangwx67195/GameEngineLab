#include <iostream>
#include <cstdio>

void swapByValue(int a, int b) {
    int c = a;
    int d = b;
    a = d;
    b = c;

    return;
}

void swapByReference(int& a, int& b) {
    // int c = a;
    // int d = b;
    // a = d;
    // b = c;

    int c = b;
    b = a;
    a = c;

    return;
}

int main() {
    int x = -2;
    int y = 5;

    swapByValue(x,y);
    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';

    swapByReference(x,y);
    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';

}