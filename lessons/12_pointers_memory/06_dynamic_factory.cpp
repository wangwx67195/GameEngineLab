#include <iostream>
#include <cstdio>
using std::cout;

int* createHealth(int initial) {
    int* p = new int(initial);

    return p;
}

int main() {
    int* p = createHealth(70);
    cout << "*p = " << *p << '\n';

    *p -= 10;
    cout << "*p = " << *p << '\n';

    delete p;
    p = nullptr;

    return 0;
}


