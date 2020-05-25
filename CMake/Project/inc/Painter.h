#pragma once

#include "ITurtle.h"

#define PI 3.14159265359

class Painter
{
public:
    Painter() = delete;
    Painter(ITurtle& a_Turtle) : m_Turtle(&a_Turtle) {};
    ~Painter() = default;

    bool DrawCircle(int a_X, int a_Y, int a_Radius)
    {
        // Draw a circle using the turtle.
        // This circle might not look like anything at all. It's not like this code will be used in production anyway.
        m_Turtle->GoTo(a_X - a_Radius, a_Y - a_Radius);
        m_Turtle->PenDown();

        const int stepSize = static_cast<int>((2.0f * PI * a_Radius) / 360.0f);

        for (std::size_t i = 0; i < 360; ++i)
        {
            m_Turtle->Forward(stepSize);
            m_Turtle->Turn(1);
        }

        m_Turtle->PenUp();

        return true;
    }

private:
    ITurtle* m_Turtle;
};