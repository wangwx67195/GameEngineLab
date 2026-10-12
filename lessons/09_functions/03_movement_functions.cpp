#include <iostream>

double updatePosition(
    double position,
    double velocity,
    double delta_time
) {
    double current_position = position + velocity * delta_time;
    return current_position;
}

double updateVelocity(double position, double velocity) {
    if (position <= 0.0) {
        velocity = -velocity;
    }
    else if (position >= 10.0) {
        velocity = -velocity;
    }

    return velocity;
}

int main() {
    double position = 2.0;
    double velocity = 2.0;
    double delta_time = 1.0;

    for (int i = 0; i < 12; ++i) {
        position = updatePosition(position, velocity, delta_time);
        velocity = updateVelocity(position, velocity) ;

        std::cout << "position , " << position << '\n';
    }

    return 0;

}


