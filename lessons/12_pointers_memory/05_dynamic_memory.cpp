#include <iostream>
#include <cstdio>
using std::cout;

int main() {
    int* p = new int(80);

    cout << "p = " << p << '\n';
    cout << "*p = " << *p << '\n';

    *p -= 15;
    cout << "*p = " << *p << '\n';
    
    int* q = p;
    cout << "p == q is " << (p == q) << '\n';
    cout << "*q = " << *q << '\n';

    delete p;
    p = nullptr;
    q = nullptr;

    cout << "p = " << p << '\n';
    cout << "q = " << q << '\n';

    return 0;
}

