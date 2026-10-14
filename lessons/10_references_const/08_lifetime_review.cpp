#include <iostream>
using std::cout;

int& shareNumber() {
    static int value = 10;
    return value;
}

int main() {
    int copy = shareNumber();
    int& alias = shareNumber();
    const int& view = shareNumber();

    cout << "copy = " << copy << '\n' << "alias = " << alias << '\n' << "view = " << view << '\n';

    copy = 99;
    cout << "copy = " << copy << '\n' << "alias = " << alias << '\n' << "view = " << view << '\n';

    alias = 20;
    cout << "copy = " << copy << '\n' << "alias = " << alias << '\n' << "view = " << view << '\n';

    // view = 30;


    return 0;
}