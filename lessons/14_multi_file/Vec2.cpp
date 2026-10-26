#include "Vec2.hpp"
#include <iostream>
using std::cout;

void translate(Vec2& position, double dx, double dy) {
    position.x += dx;
    position.y += dy;

    return;
}

void printPosition(const Vec2& position) {
    cout << position.x << " " << position.y << '\n';

    return;
}