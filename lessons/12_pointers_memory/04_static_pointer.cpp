#include <iostream>
#include <cstdio>
using std::cout;

int* storedNumber() {
    static int a = 10;

    return &a;
}

int main() {
    int* p = storedNumber();
    int* q = storedNumber();

    // cout << "a = " << a <<'\n';

    cout << "p = " << p << '\n';
    cout << "q = " << q << '\n';
    cout << "p == q " << (p == q) << '\n';
    
    cout << "*p = " << *p << '\n';
    cout << "*q = " << *q << '\n';

    *p = 25;
    cout << "*q = " << *q << '\n';
    
    int* b = storedNumber();
    cout << "*b = " << *b << '\n';

    return 0;
}


