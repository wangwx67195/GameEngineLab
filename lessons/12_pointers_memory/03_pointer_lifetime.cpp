#include <iostream>
#include <cstdio>
using std::cout;

int main() {
    int* p = nullptr;
    
    {
        int health = 70;
        p = &health;

        *p -= 10;
        cout << "health = " << health << '\n' << "*p = " << *p << '\n';

        p = nullptr;
        cout << "health = " << health << '\n';
    }

    if (p == nullptr) {
        cout << "没有可访问的目标" << '\n';
    }


    return 0;
}

