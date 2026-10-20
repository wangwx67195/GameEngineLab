#include <iostream>
#include <cstdio>
using std::cout;

struct Vec2 {
    double x = 0;
    double y = 0;

    void translate(double dx, double dy) {
        x += dx;
        y += dy;

        return;
    }

    void print() const {
        cout << "x = " << x << '\n';
        cout << "y = " << y << '\n';

        return;
    }

    // void add() const {
    //     x += 10;
    //     y += 10;

    //     return;
    // }

    double lengthSquared() const {
        double square = x * x + y * y;
        // cout << "square = " << square << '\n';

        return square;
    }

};

int main() {
    Vec2 position{};
    double p_square = position.lengthSquared();
    cout << p_square << '\n';
    Vec2 a{3, 4};
    double a_square = a.lengthSquared();
    cout << a_square << '\n';
    Vec2 b{-1, 2};
    double b_square = b.lengthSquared();
    cout << b_square << '\n';

    a.translate(1, -2);
    a.print();
    a_square = a.lengthSquared();
    cout << a_square << '\n';
    b.print();

    const Vec2 frozen{6, 8};
    frozen.print();
    double frozen_square = frozen.lengthSquared();
    cout << frozen_square << '\n';
    // frozen.translate(0.0, 0.0);

    return 0;
}



