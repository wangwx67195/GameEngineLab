#include "Vec2.hpp"
#include <iostream>
#include <cstdio>
using std::cout;
// cout will be used in main.cpp

// void translate(Vec2& position, double dx, double dy);
// void printPosition(const Vec2& position);
// Functions have beend declared in Vec2.hpp file, no need to declare here

int main() {
    // Vec2 default_position;
    // printPosition(default_position);

    // int probe_1 = probe();
    // cout << "probe = " << probe_1 << '\n';

    // Vec2 position{2.0, -1.0};
    // printPosition(position);

    // translate(position, 3.0, 4.0);
    // printPosition(position);

    Vec2 default_position_new{};
    cout << default_position_new.x << ", " << default_position_new.y << '\n';
    cout << default_position_new.lengthSquared() << '\n'; 
    Vec2 a{2.0, -1.0};
    Vec2 b = a;
    Vec2* c = &a;
    cout << "(*c) " << (*c).x << ", " << (*c).y << '\n';
    a.translate(3.0, 4.0);
    cout << "a " << a.x << ", " << a.y << '\n';
    cout << "a " << a.lengthSquared() << '\n';
    cout << "b " << b.x << ", " << b.y << '\n';
    cout << "b " << b.lengthSquared() << '\n';
    cout << "c " << c << '\n';
    cout << "(*c) " << (*c).x << ", " << (*c).y << '\n';

    const Vec2 frozen{-3.0, 4.0};
    cout << "frozen " << frozen.lengthSquared() << '\n';

    return 0;
}