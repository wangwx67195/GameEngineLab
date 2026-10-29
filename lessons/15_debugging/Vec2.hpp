#pragma once
// #ifndef GAMEENGINELAB_LESSON14_VEC2_HPP
// #define GAMEENGINELAB_LESSON14_VEC2_HPP

int probe();
void cout_function();

struct Vec2 {
    double x = 0.0;
    double y = 0.0;

    void translate(double dx, double dy);
    double lengthSquared() const;
};

// #endif
