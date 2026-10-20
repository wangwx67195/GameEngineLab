#include <iostream>
#include <cstdio>
using std::cout;

struct Vec2 {
    double x = 0.0;
    double y = 0.0;
};

void printPosition(const Vec2& position) {
    cout << "Vec2.x = " << position.x << '\n';
    cout << "Vec2.y = " << position.y << '\n';

    return;
}

void translate(Vec2& position, double dx, double dy) {
    position.x += dx;
    position.y += dy;

    return;
}

int main() {
    Vec2 default_position{};
    printPosition(default_position);
    Vec2 position{2.0, -1.0};
    printPosition(position);
    translate(position, 3.0, 4.0);
    printPosition(position);
    translate(position, -5, -3); 
    printPosition(position);
    translate(position, 0, 0);
    printPosition(position);

    Vec2 copy = position;
    copy.x = 1;
    copy.y = 1;
    printPosition(copy);
    printPosition(position);
    Vec2& p = position;
    p.x = 2;
    p.y = 2;
    printPosition(p);
    printPosition(position);

    return 0;
}



