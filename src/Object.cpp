#include "Object.hpp"
Object::Object()
{
    this->velocity = {{0.0f, 0.0f}};
    this->position = {{0.0f, 0.0f}};
    this->radius = 50.0f;
    this->mass = 0;
}
Object::Object(std::vector<float> velocity, std::vector<float> position, float radius, float mass)
{
    this->velocity = velocity;
    this->position = position;
    this->radius = radius;
    this->mass = mass;
}
// Update the current Position
void Object::updatePos(float dt)
{
    position[0] += acceleration[0] * dt;
    position[1] += acceleration[1] * dt;
    
    position[0] += velocity[0] * dt;
    position[1] += velocity[1] * dt;
}
// Good
void Object::drawCircle() const
{
    const int segment = 100;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(position[0], position[1]);
    for (int i = 0; i <= segment; i++)
    {
        float angle = 2.0f * static_cast<float>(M_PI) * i / segment;
        float x = position[0] + radius * std::cos(angle);
        float y = position[1] + radius * std::sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}
void Object::gravitationalForce(const Object& other)
{
    float dx = other.position[0] - position[0];
    float dy = other.position[1] - position[1];
    //Using pythagorian method to find distance
    float distance = std::sqrt(dx * dx + dy * dy);
    float a = G * other.mass / distance; // Magnitude force
    this->acceleration[0] += a * dx / distance;
    this->acceleration[1] += a * dy / distance; 
}