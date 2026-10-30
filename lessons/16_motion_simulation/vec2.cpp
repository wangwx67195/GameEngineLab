#include <iostream>
#include "vec2.hpp"
#include <vector>
using std::cout;

void updateBodies(std::vector<Body>& bodies, double simulationTime, double deltaTime) {
    for (int step = 0; step < simulationTime / deltaTime; ++step) {
        for (Body& body : bodies) {
            if ((step + 1) * deltaTime > simulationTime) {
                body.position.x += body.velocity.x * (simulationTime - step * deltaTime); //这里的逻辑有点小混淆，但是我不想改了
                body.position.y += body.velocity.y * (simulationTime - step * deltaTime);        
                
                return;
            }
            body.position.x += body.velocity.x * deltaTime;
            body.position.y += body.velocity.y * deltaTime;
        }
    }

    return;
}

void printBodies(const std::vector<Body>& bodies) {
    for (const Body& body : bodies) {
        cout << "body's (x,y) = " << body.position.x << ',' << body.position.y << '\n';
    }

    return;
}