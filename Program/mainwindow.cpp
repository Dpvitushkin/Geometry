#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <vector>
#include "Object.cpp"
#include "Triangle.cpp"
#include "Square.cpp"
#include "Circle.cpp"

class mainwindow
{
public:
    const GLuint WIDTH = 800, HEIGHT = 800;
    GLFWwindow* window;
    std::vector<Object*> objects;
    int selected = 0;

	mainwindow()
	{
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        window = glfwCreateWindow(WIDTH, HEIGHT, "Figures", nullptr, nullptr);
        glfwMakeContextCurrent(window);
        glewExperimental = GL_TRUE;
        glewInit();
        glViewport(0, 0, WIDTH, HEIGHT);
        std::cout << "mainwindow constructed" << std::endl;
	}
    GLFWwindow* return_window();
    void create_Triangle();
    void create_Square();
    void create_Circle();
    void delete_object(int i);
    void draw_scene();
    void get_command(std::string command);
    void select(int up_down);
    int return_number_of_objects();
    
    
};

void mainwindow::create_Triangle()
{
    this->objects.push_back(new Triangle());
    selected = this->objects.size() - 1;
}

void mainwindow::create_Square()
{
    this->objects.push_back(new Square());
    selected = this->objects.size() - 1;
}

void mainwindow::create_Circle()
{
    this->objects.push_back(new Circle());
    selected = this->objects.size() - 1;
}

void mainwindow::delete_object(int i)
{
    if (selected != 0) selected--;
    std::vector<Object*>::iterator it = objects.begin();
    delete objects[i];
    objects.erase(it + i);
}

GLFWwindow* mainwindow::return_window()
{
    return window;
}

void mainwindow::draw_scene()
{
    for (int i = 0; i<objects.size(); i++)
    {
        objects[i]->draw();
    }
}

int mainwindow::return_number_of_objects()
{
    return this->objects.size();
}

void mainwindow::get_command(std::string command)
{
    if (command == "W_action" && this->return_number_of_objects()!=0) objects[selected]->translate(0, 0.1);
    if (command == "S_action" && this->return_number_of_objects() != 0) objects[selected]->translate(0, -0.1);
    if (command == "A_action" && this->return_number_of_objects() != 0) objects[selected]->translate(-0.1, 0);
    if (command == "D_action" && this->return_number_of_objects() != 0) objects[selected]->translate(0.1, 0);
    if (command == "1_action") this->create_Triangle();
    if (command == "2_action") this->create_Square();
    if (command == "3_action") this->create_Circle();
    if (command == "C_action" && this->return_number_of_objects() != 0) objects[selected]->change_color();
    if (command == "Backspace_action" && this->return_number_of_objects() != 0) this->delete_object(selected);

    if (command == "E_action" && this->return_number_of_objects() != 0)
    {
        if (selected != 0) selected--;
        else selected = objects.size() - 1;
    }
}



