#include <iostream>

int main() {
    for (int frame = 0; frame < 10; ++frame) {
        std::cout<< frame << '\n';
        if (frame % 3 == 0) {
            std::cout << "Special Update" << '\n';
        }
    }

    return 0;
}