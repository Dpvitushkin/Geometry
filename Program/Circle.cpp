#pragma once
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Object.cpp"
#include <iostream>
#include <vector>
#include <cmath>
#define PI 3.14159265358979323846

class Circle : public Object
{
private:
    GLuint VBO, VAO, EBO;
    GLfloat vertices[6*31];
    GLuint indices[3*30];
public:
    Circle()
    {

        generate_data();
        setup();
        Shader ourShader("shader.vs", "shader.fs");
        ourShader.Use();
    }
    void generate_data();
    void setup();
    void draw();
    void translate(float x, float y);
    void change_color();

};

void Circle::generate_data()
{
    float angle =  2*PI / 30;
    vertices[0] = 0.0f;
    vertices[1] = 0.0f;
    vertices[2] = 0.0f;
    vertices[3] = 1.0f;
    vertices[4] = 0.0f;
    vertices[5] = 0.0f;
    indices[0] = 0;
    indices[1] = 1;
    indices[2] = 2;
    for (int i = 1; i <= 30; i++)
    {
        vertices[i * 6] = sin(angle * (i-1))*0.25;
        vertices[i * 6 + 1] = cos(angle * (i-1))*0.25;
        vertices[i * 6 + 2] = 0.0f;
        vertices[i * 6 + 3] = 1.0f;
        vertices[i * 6 + 4] = 0.0f;
        vertices[i * 6 + 5] = 0.0f;
        if (i != 30)
        {
            indices[i * 3] = 0;
            indices[i * 3 + 1] = i + 1;
            indices[i * 3 + 2] = i + 2;
        }
        indices[29 * 3 + 2] = 1;    
    }
}
void Circle::setup()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);

}

void Circle::draw()
{
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, 90, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Circle::translate(float x, float y)
{
    for (int i = 0; i < 31; i++)
    {
        vertices[i * 6] += x;
        vertices[i * 6 + 1] += y;
    }
    this->setup();
}

void Circle::change_color()
{
    float a, b, c;
    if (vertices[3] == 1) { a = 0; b = 1; c = 0; }
    if (vertices[4] == 1) { a = 0; b = 0; c = 1; }
    if (vertices[5] == 1) { a = 1; b = 0; c = 0; }
    for (int i = 0; i <= 30; i++)
    {
        vertices[i * 6 + 3] = a;
        vertices[i * 6 + 4] = b;
        vertices[i * 6 + 5] = c;
    }
    this->setup();
}

