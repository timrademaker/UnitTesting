#pragma once

#include "GameObject.h"

#include <vector>
#include <memory>

// To make this class work with both testing- and non-testing code, we need to templatize it.
// Alternatively, we could use the adapter from GameObject_Test.h (and move it to GameObject.h) to avoid templates
template<class GameObjectBase = GameObject>
class GameObjectManager
{
public:
    GameObjectManager() = default;
    ~GameObjectManager() = default;

    void AddObject(std::shared_ptr<GameObjectBase> a_Object)
    {
        m_Objects.push_back(std::move(a_Object));
    }

    void UpdateObjects(float a_DeltaTime)
    {
        for (auto& obj : m_Objects)
        {
            obj->OnUpdate(a_DeltaTime);
        }
    }

    void MoveObjects(float a_X, float a_Y, float a_Z)
    {
        for (auto& obj : m_Objects)
        {
            obj->MoveBy(a_X, a_Y, a_Z);
        }
    }

private:
    std::vector<std::shared_ptr<GameObjectBase>> m_Objects;
};