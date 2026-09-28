#include "Engine.hpp"
#include <ctime>
#include "Object.hpp"
std::vector<Object> objs = {Object(std::vector<float>{50.0f, 100.0f}, std::vector<float>{10.0f, 10.0f}, 50.0f, 10.0f),
                            Object(std::vector<float>{50.0f, 150.0f}, std::vector<float>{250, 240}, 30.0f, 10.0f)};
//,Object(std::vector<float>{50.0f, 150.0f}, std::vector<float>{250, 240}, 50)
int main()
{
    Engine engine;
    // keep running until someone closes the window
    float previousTime = static_cast<float>(glfwGetTime());
    while (!glfwWindowShouldClose(engine.window))
    {
        engine.run();
        float currentTime = static_cast<float>(glfwGetTime());
        float dt = currentTime - previousTime;
        previousTime = currentTime;
        //Reset acceleration 
        for(auto &p: objs){
            p.resetAcceleration();
        }
        //Calculate the gravity between two objects
        for(int i = 0; i < objs.size(); i++){
            for(int j = 0; j < objs.size(); j++){
                if(i != j){
                    objs[i].gravitationalForce(objs[j]);
                }
            }
        }
        
        for (auto &p : objs)
        {
            float bottom = -engine.HEIGHT / 2.0f + p.radius;
            float top = engine.HEIGHT / 2.0f - p.radius;
            float left = -engine.WIDTH / 2.0f + p.radius;
            float right = engine.WIDTH / 2.0f - p.radius;
            p.updatePos(dt);
            p.drawCircle();
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
