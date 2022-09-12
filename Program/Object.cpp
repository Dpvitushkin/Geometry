#pragma once

class Object
{
public:

    virtual void setup() = 0;
    virtual void draw() = 0;
    virtual void translate(float x, float y) = 0;
    virtual void change_color() = 0;

};
