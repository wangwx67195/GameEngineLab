#include "Vec2.hpp"
#include <iostream>
using std::cout;

int probe() {
    return 1;
}

void Vec2::translate(double dx, double dy) {
    x += dx;
    y += dy;

    return;
}

double Vec2::lengthSquared() const {
    return x*x + y*y;
}

// code comment 
