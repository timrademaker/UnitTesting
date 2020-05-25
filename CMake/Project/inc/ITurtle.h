#pragma once

class ITurtle
{
public:
    ITurtle() = default;
    virtual ~ITurtle() = default;

    virtual void PenUp() = 0;
    virtual void PenDown() = 0;
    virtual void Forward(int a_Distance) = 0;
    virtual void Turn(int a_Degrees) = 0;
    virtual void GoTo(int a_X, int a_Y) = 0;
    virtual int GetX() const = 0;
    virtual int GetY() const = 0;
};