#include <iostream>
#include "vec2.hpp"
#include <vector>

int main() {
    Body body1{{0,0}, {2,1}};
    Body body2{{10, -2}, {-1, 0.5}};
    Body body3{{-3, 5}, {0, 0}};
    std::vector<Body> bodies = {body1, body2, body3};
    updateBodies(bodies, 4.33, 0.3);
    printBodies(bodies);

    return 0;
}