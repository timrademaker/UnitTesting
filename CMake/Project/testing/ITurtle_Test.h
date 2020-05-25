#pragma once

#include "ITurtle.h"

#include <gmock/gmock.h>


class MockTurtle : public ITurtle
{
public:
    MOCK_METHOD(void, PenUp, (), (override));
    MOCK_METHOD(void, PenDown, (), (override));
    MOCK_METHOD(void, Forward, (int a_Distance), (override));
    MOCK_METHOD(void, Turn, (int a_Degrees), (override));
    MOCK_METHOD(void, GoTo, (int a_X, int a_Y), (override));
    MOCK_METHOD(int, GetX, (), (const, override));
    MOCK_METHOD(int, GetY, (), (const, override));
};