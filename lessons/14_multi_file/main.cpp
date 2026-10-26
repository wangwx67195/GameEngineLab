#include "Vec2.hpp"
#include <iostream>
#include <cstdio>
// using std::cout;
// cout will be used in main.cpp

// void translate(Vec2& position, double dx, double dy);
// void printPosition(const Vec2& position);
// Functions have beend declared in Vec2.hpp file, no need to declare here

int main() {
    Vec2 default_position;
    printPosition(default_position);

    Vec2 position{2.0, -1.0};
    printPosition(position);

    translate(position, 3.0, 4.0);
    printPosition(position);

    return 0;
}