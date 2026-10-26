#pragma once
// #ifndef GAMEENGINELAB_LESSON14_VEC2_HPP
// #define GAMEENGINELAB_LESSON14_VEC2_HPP

int probe();
struct Vec2 {
    double x = 0.0;
    double y = 0.0;
};

void translate(Vec2& position, double dx, double dy);
void printPosition(const Vec2& position);

// #endif