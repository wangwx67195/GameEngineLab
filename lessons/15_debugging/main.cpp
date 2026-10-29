#include "Vec2.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

using std::cout;

void cout_function(Vec2 a) {
    cout << a.x << ", " << a.y << '\n';
    cout << a.lengthSquared() << '\n';

    return;
}

bool nearlyEqual(
    double actual,
    double expected,
    double tolerance = 1e-9
) {
    bool equal = (std::abs(actual - expected)) < tolerance;

    return equal;
}

int main() {
    Vec2 a{2.0, -1.0};
    Vec2 b = a;

    a.translate(3.0, 4.0);
    assert(nearlyEqual(a.lengthSquared(), 34));

    cout << "assert not ran" << '\n';

    cout_function(a);
    cout_function(b);
    

    return 0;
}