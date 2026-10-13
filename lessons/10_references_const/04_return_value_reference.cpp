#include <iostream>

int makeValue(int value) {

    return value;

}

int& accessValue(int& value) {

    return value += 10;

}

int makeAccess(int& value) {

    return value += 10;

}

int main() {
    int original = 10;
    int copy = makeValue(original);
    int& alias = accessValue(original);
    int acc = makeAccess(original);
    std::cout << "original = " << original << '\n';
    std::cout << "copy = " << copy << '\n';
    std::cout << "alias = " << alias << '\n';
    std::cout << "acc = " << acc << '\n';

    copy = 20;
    std::cout << "original = " << original << '\n';
    std::cout << "copy = " << copy << '\n';
    std::cout << "alias = " << alias << '\n';
    std::cout << "acc = " << acc << '\n';


    alias = 40;
    std::cout << "original = " << original << '\n';
    std::cout << "copy = " << copy << '\n';
    std::cout << "alias = " << alias << '\n';
    std::cout << "acc = " << acc << '\n';


    return 0;
}