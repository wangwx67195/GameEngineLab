#include <iostream>
using std::cout;

double advancePosition(
    double position,
    double velocity,
    double delta_time = 0.5
) {
    if (position < 0 || position > 10) {
        velocity = -velocity;
    }
    position = position + velocity * delta_time;

    return position;
}

int main() {
    double p1 = advancePosition(2.0, 2.0);
    double p2 = advancePosition(2.0, 2.0, 1.0);
    double p3 = advancePosition(2.0, 2.0, 0.0);
    double p4 = advancePosition(2.0, -2.0);

    cout << p1 << '\n' << p2 << '\n' << p3 << '\n' << p4;

    return 0;
}