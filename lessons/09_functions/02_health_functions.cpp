#include <iostream>
#include <cstdio>

void printHealthStatus(int health) {

    if (health <= 0) {
        std::cout << "Game Over" << '\n';
    }
    else if (health <= 20) {
        std::cout << "Warning" << '\n';
    }
    else if (health <= 100) {
        std::cout << "Healthy" << '\n';
    }
    else {
        std::cout << "Invalid Health" << '\n';
    }

    return;

}

bool isAlive(int health) {
    if (health > 0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int health;
    std::cin >> health;
    printHealthStatus(health);
    bool is_Healthy = isAlive(health);
    printf("%d\n", is_Healthy);
}


