#pragma once
#include <vector>

struct Vec2 {
    double x = 0.0;
    double y = 0.0;
};

struct Body {
    Vec2 position{};
    Vec2 velocity{};
};

void updateBodies(std::vector<Body>& bodies, double simulationTime, double deltaTime);
void printBodies(const std::vector<Body>& bodies);