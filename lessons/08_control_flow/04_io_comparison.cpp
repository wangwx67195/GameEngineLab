#include <iostream>
#include <cstudio>

int main() {
    int score = 95;
    double speed = 3.14159;
    std::printf("Score = %d\n", score);
    std::cout << "Score = " << score << '\n';
    std::printf("Speed = %.2f\n", speed);
    std::cout << "Speed = " << speed << '\n';

    return 0;
}