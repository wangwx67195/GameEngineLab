#include <iostream>
using std::cout;

int main() {
    int health = 80;
    int* p = &health;
    cout << "health = " << health << '\n';
    cout << "&health = " << &health << '\n';
    cout << "p = " << p << '\n';
    cout << "*p = " << *p << '\n';
    cout << "p == &health = " << (p == &health) << '\n';

    *p -= 15;
    cout << "health = " << health << '\n';
    cout << "*p = " << *p << '\n';

    int shield = 30;
    p = &shield;

    *p += 5;
    cout << "health = " << health << '\n';
    cout << "shield = " << shield << '\n';
    cout << "*p = " << *p << '\n';

    cout << "p == &health " << (p == &health) << '\n';
    cout << "p == &shield " << (p == &shield) << '\n';

    return 0;
}





