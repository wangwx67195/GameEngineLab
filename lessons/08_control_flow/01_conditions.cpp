#include <iostream>

int main(){
    int health;

    std::cin >> health;

    if (health <= 0){
        std::cout << "Game Over" << '\n';
    }
    else if (health <= 20){
        std::cout << "Warning" << '\n';
    }
    else if (health > 100) {
        std::cout << "Invalid Health" << '\n';
    }
    else {
        std::cout << "Healthy" << '\n';
    }

    return 0;
}