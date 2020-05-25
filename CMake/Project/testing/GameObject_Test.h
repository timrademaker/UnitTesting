#pragma once

#include <gmock/gmock.h>

#include "GameObject.h"

// Note: GameObject mixes virtual- and non-virtual functions. We want to test both. 

// We just create a mock class that has the functionality we need.
// This does require us to templatize the class that uses the object we are mocking

class MockGameObject
{
public:
    MOCK_METHOD(void, OnUpdate, (float a_DeltaTime));
    MOCK_METHOD(void, MoveBy, (float a_X, float a_Y, float a_Z));
};


// Alternatively, we could create an adapter.
// This adapter only needs to implement the functions the tests will call.
// In an actual implementation, this would be placed in a non-testing file and would be used by GameObjectManager

class GameObjectAdapter
{
public:
    GameObjectAdapter() = default;
    ~GameObjectAdapter() = default;

    virtual void OnUpdate(float a_DeltaTime)
    {
        m_Object.OnUpdate(a_DeltaTime);
    }

    virtual void MoveBy(float a_X, float a_Y, float a_Z)
    {
        m_Object.MoveBy(a_X, a_Y, a_Z);
    }

private:
    GameObject m_Object;
};

class MockGameObjectAdapter : public GameObjectAdapter
{
public:
    MOCK_METHOD(void, OnUpdate, (float a_DeltaTime), (override));
    MOCK_METHOD(void, MoveBy, (float a_X, float a_Y, float a_Z), (override));
};
