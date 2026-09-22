#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;
struct Engine
{
    // Set up Window
    GLFWwindow *window;
    int WIDTH = 800, HEIGHT = 600;
    Engine()
    {
        // Check if openGlew is available
        if (!glfwInit())
        {
            cerr << "glfw didn't start" << endl;
            exit(EXIT_FAILURE);
        }

        // ask the operating system for a window
        window = glfwCreateWindow(WIDTH, HEIGHT, "Solar System Simumlator", nullptr, nullptr);
        if (!window)
        {
            cerr << "no window" << endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        // point every future drawing command at this window
        glfwMakeContextCurrent(window);
        glewInit();

        int fbWidth, fbHeight;
        glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
        glViewport(0, 0, fbWidth, fbHeight);
    }

    // this runs once per frame
    void run()
    {
        // wipe the screen to almost-black
        glClearColor(0.05f, 0.05f, 0.08f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // put (0, 0) in the middle instead of the corner
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-WIDTH / 2.0, WIDTH / 2.0, -HEIGHT / 2.0, HEIGHT / 2.0, -1.0, 1.0);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }
};