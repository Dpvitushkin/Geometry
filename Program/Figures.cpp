#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "Shader.h"
#include "mainwindow.cpp"
#include <iostream>



void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
std::string command;

int main()
{
    mainwindow Win;
    GLFWwindow* window = Win.return_window();

    glfwSetKeyCallback(window, key_callback);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        Win.get_command(command);
        if (Win.return_number_of_objects() != 0)
        {
            Win.draw_scene();
        }



        glfwSwapBuffers(window);
        command = "NONE";
    }
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    if (key == GLFW_KEY_W && action == GLFW_PRESS)
    {
        std::cout << "W pressed -> move up" << std::endl;
        command = "W_action";
    }
    if (key == GLFW_KEY_S && action == GLFW_PRESS)
    {
        std::cout << "S pressed -> move down" << std::endl;
        command = "S_action";
    }
    if (key == GLFW_KEY_D && action == GLFW_PRESS)
    {
        std::cout << "D pressed -> move right" << std::endl;
        command = "D_action";
    }
    if (key == GLFW_KEY_A && action == GLFW_PRESS)
    {
        std::cout << "A pressed -> move left" << std::endl;
        command = "A_action";
    }
    if (key == GLFW_KEY_1 && action == GLFW_PRESS)
    {
        std::cout << "1 pressed -> create Triangle" << std::endl;
        command = "1_action";
    }
    if (key == GLFW_KEY_2 && action == GLFW_PRESS)
    {
        std::cout << "2 pressed -> create Square" << std::endl;
        command = "2_action";
    }
    if (key == GLFW_KEY_3 && action == GLFW_PRESS)
    {
        std::cout << "3 pressed -> create Circle" << std::endl;
        command = "3_action";
    }
    if (key == GLFW_KEY_E && action == GLFW_PRESS)
    {
        std::cout << "E pressed -> change selection" << std::endl;
        command = "E_action";
    }
    if (key == GLFW_KEY_C && action == GLFW_PRESS)
    {
        std::cout << "C pressed -> change color" << std::endl;
        command = "C_action";
    }
    if (key == GLFW_KEY_BACKSPACE && action == GLFW_PRESS)
    {
        std::cout << "Backspace pressed -> delete object" << std::endl;
        command = "Backspace_action";
    }
}
