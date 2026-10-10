#include <iostream>

int main() {
    double position = 2.0;
    double velocity = 2.0;
    double delta_time = 1.0;

    for (int i = 0; i < 12; ++i) {
        position += velocity * delta_time;
        std::cout << "Position = " << position << '\n';
        
        if (position >= 10.0) {
            velocity *= -1.0;
        }
        else if (position <= 0.0) {
            velocity *= -1.0;
        }
    }

    return 0;
}