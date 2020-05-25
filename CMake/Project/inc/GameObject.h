#pragma once

class GameObject
{
public:
    GameObject() = default;
    virtual ~GameObject() = default;

    virtual void OnBeginPlay() {}
    virtual void OnUpdate(float a_DeltaTime) {}
    virtual void OnDestroy() {}

    void MoveBy(float a_X, float a_Y, float a_Z)
    {
        m_Position[0] += a_X;
        m_Position[1] += a_Y;
        m_Position[2] += a_Z;
    }

private:
    float m_Position[3] = { 0.0f, 0.0f, 0.0f };
};