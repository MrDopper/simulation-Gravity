#include "Engine.hpp"
#include <ctime>
#include "Object.hpp"
#include <thread>
#include <chrono>
std::vector<Object> objs = {{Object(std::vector<float>{10.0f, 20.0f}, std::vector<float>{10.0f, 10.0f}, 50.0f),
                             Object(std::vector<float>{50.0f, 150.0f}, std::vector<float>{250, 240}, 30)}};
//,Object(std::vector<float>{50.0f, 150.0f}, std::vector<float>{250, 240}, 50)
int main()
{
    Engine engine;
    // keep running until someone closes the window
    while (!glfwWindowShouldClose(engine.window))
    {
        engine.run();
        float currentTime = static_cast<float>(glfwGetTime());
        for (auto &p : objs)
        {
            float bottom = -engine.HEIGHT / 2.0f + p.radius;
            float top = engine.HEIGHT / 2.0f - p.radius;
            float left = -engine.WIDTH / 2.0f + p.radius;
            float right = engine.WIDTH / 2.0f - p.radius;
            float dt = p.getDeltaTime(currentTime);
            p.acceleration(p.velocity[0], p.velocity[1], dt);
            p.updatePos(p.position[0], p.position[1], p.velocity[0], p.velocity[1], dt);
            p.drawCircle(p.position[0], p.position[1], p.radius);
            if (p.position[0] <= left)
            {
                p.position[0] = left;
                p.velocity[0] = -p.velocity[0] * 0.95f;
            }
            else if (p.position[0] >= right)
            {
                p.position[0] = right;
                p.velocity[0] = -p.velocity[0] * 0.95f;
            }

            if (p.position[1] <= bottom)
            {
                p.position[1] = bottom;
                p.velocity[1] = -p.velocity[1] * 0.95f;
            }
            else if (p.position[1] >= top)
            {
                p.position[1] = top;
                p.velocity[1] = -p.velocity[1] * 0.95f;
            }
        }
        glfwSwapBuffers(engine.window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
