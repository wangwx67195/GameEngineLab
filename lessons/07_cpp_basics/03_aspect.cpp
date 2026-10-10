#include <iostream>

int main(){
    int width = 800;
    int height = 600;

    std::cin >> width;

    double aspect_int = width / height;
    double aspect_double = double(width) / double(height);

    std::cout << "aspect_int = " << aspect_int << '\n';
    std::cout << "aspect_double = " << aspect_double << '\n';

    return 0;
}