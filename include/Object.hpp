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
    float radius;
    float dt;
    float finalTime = 0;
    float mass;
    const float g = -9.81f; // Gravity

    Object()
    {
        this->velocity = {{0.0f, 0.0f}};
        this->position = {{0.0f, 0.0f}};
        this->radius = 50.0f;
        this->mass = 0;
    }
    Object(std::vector<float> velocity, std::vector<float> position, float radius, float mass)
    {
        this->velocity = velocity;
        this->position = position;
        this->radius = radius;
        this->mass = mass;
    }
    // Update the current Position
    void updatePos(float initalPosX, float initalPosY, float initalVelX, float initalVelY, float dt)
    {
        this->position[0] = initalPosX + initalVelX * dt;
        this->position[1] = initalPosY + initalVelY * dt + 0.5f * g * dt * dt;
    }
    void acceleration(float initalVelX, float initalVelY, float dt)
    {
        this->velocity[0] = initalVelX + g * dt;
        this->velocity[1] = initalVelY + g * dt;
    }
    // Good
    void drawCircle(float centerX, float centerY, float radius)
    {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(centerX, centerY);
        for (float angle = 0.0f; angle <= 2.0f * static_cast<float>(M_PI); angle += 0.01f)
        {
            float x = centerX + radius * std::cos(angle);
            float y = centerY + radius * std::sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
    }
    // Good
    float getDeltaTime(float currentTime)
    {
        dt = currentTime - finalTime;
        finalTime = currentTime;
        return dt;
    }
};