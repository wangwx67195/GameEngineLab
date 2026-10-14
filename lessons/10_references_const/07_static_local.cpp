#include <iostream>
using std::cout;

int countNormal() {
    int countnormal = 0;
    countnormal +=1;
    
    return countnormal;
}

int countStatic() {
    static int countstatic = 0;
    countstatic += 1;

    return countstatic;
}

int main() {
    int c_normal = countNormal();
    cout << "c_normal = " << c_normal << '\n';
    c_normal = countNormal();
    cout << "c_normal = " << c_normal << '\n';
    c_normal = countNormal();
    cout << "c_normal = " << c_normal << '\n';

    int c_static = countStatic();
    cout << "c_static = " << c_static << '\n';
    c_static = countStatic();
    cout << "c_static = " << c_static << '\n';
    c_static = countStatic();
    cout << "c_static = " << c_static << '\n';

    return 0;
}