#include "Vec2.hpp"
#include <iostream>
using std::cout;

void cout_function(Vec2 a) {
    cout << a.x << ", " << a.y << '\n';
    cout << a.lengthSquared() << '\n';

    return;
}

int main() {
    Vec2 a{2.0, -1.0};
    Vec2 b = a;

    a.translate(3.0, 4.0);

    cout_function(a);
    cout_function(b);
    

    return 0;
}