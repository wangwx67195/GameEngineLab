#include <iostream>
#include <cstdio>

int main() {
    int score = 10;

    {
        // int score = 99;
        score += 1;

        std::cout << "inner score = " << score << '\n';
    }

    std::cout << "outer score = " << score << '\n';


}