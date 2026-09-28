#pragma once
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>
class Object
{
public:
    std::vector<float> velocity;
    std::vector<float> position;
    std::vector<float> acceleration;
    float radius;
    float mass;
    const float g = -9.81f; // Gravity
    const float G = 100.0f; // Gravitational 6.674e-11f

    void resetAcceleration()
    {
        acceleration = {0.0f, 0.0f};
    }
    Object();
    Object(std::vector<float> velocity, std::vector<float> position, float radius, float mass);
    void updatePos(float dt);
    void drawCircle() const;
    void gravitationalForce(const Object &other);
};