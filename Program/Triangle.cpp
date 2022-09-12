#pragma once

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Shader.h"
#include "Object.cpp"
#include <iostream>
#include <vector>
#include <cmath>

class Triangle : public Object
{
private:
    GLuint VBO, VAO, EBO;
    GLfloat vertices[18] = {
         -0.3f,  0.0f,  0.0f,  1.0f,0.0f,0.0f,
          0.3f,  0.0f,  0.0f,  1.0f,0.0f,0.0f,
          0.0f,  0.3f,  0.0f,  1.0f,0.0f,0.0f };
    GLuint indices[3] = { 0, 1, 2 };

public:
    Triangle()
    {
        setup();
        Shader ourShader("shader.vs", "shader.fs");
        ourShader.Use();
    }
    void setup();
    void draw();
    void translate(float x, float y);
    void change_color();

};

void Triangle::setup()
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

void Triangle::draw()
{
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void Triangle::translate(float x, float y)
{
    vertices[0] += x;
    vertices[6] += x;
    vertices[12] += x;
    vertices[1] += y;
    vertices[7] += y;
    vertices[13] += y;
    this->setup();
}

void Triangle::change_color()
{
    float a, b, c;
    if (vertices[3] == 1) { a = 0; b = 1; c = 0; }
    if (vertices[4] == 1) { a = 0; b = 0; c = 1; }
    if (vertices[5] == 1) { a = 1; b = 0; c = 0; }
    vertices[3] = a;
    vertices[4] = b;
    vertices[5] = c;
    vertices[9] = a;
    vertices[10] = b;
    vertices[11] = c;
    vertices[15] = a;
    vertices[16] = b;
    vertices[17] = c;
    this->setup();
}

