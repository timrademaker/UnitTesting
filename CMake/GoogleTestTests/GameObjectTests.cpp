#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "GameObjectManager.h"

#include "GameObject_Test.h"


using ::testing::_;

TEST(GameObjectTest, Update)
{
    // Create mock object
    auto go = std::make_shared<MockGameObjectAdapter>();

    // Set expectations
    EXPECT_CALL(*go, OnUpdate(_))
        .Times(1);

    // Set up for the execution of actions
    GameObjectManager<GameObjectAdapter> man;
    man.AddObject(go);

    // Execute actions
    man.UpdateObjects(1.0f);
}

TEST(GameObjectTest, MoveByUsingAdapter)
{
    // Create mock object
    auto go = std::make_shared<MockGameObjectAdapter>();
    auto go2 = std::make_shared<MockGameObjectAdapter>();
    auto go3 = std::make_shared<MockGameObjectAdapter>();

    // Set expectations
    EXPECT_CALL(*go, MoveBy(_, _, _))
        .Times(1);

    EXPECT_CALL(*go2, MoveBy(_, _, _))
        .Times(1);

    EXPECT_CALL(*go3, MoveBy(_, _, _))
        .Times(1);


    // Set up for the execution of actions
    GameObjectManager<GameObjectAdapter> man;
    man.AddObject(go);
    man.AddObject(go2);
    man.AddObject(go3);

    // Execute actions
    man.MoveObjects(1.0f, 0.0f, 0.0f);
}


TEST(GameObjectTest, MoveBy)
{
    // Create mock object
    auto go = std::make_shared<MockGameObject>();
    auto go2 = std::make_shared<MockGameObject>();
    auto go3 = std::make_shared<MockGameObject>();

    // Set expectations
    EXPECT_CALL(*go, MoveBy(_, _, _))
        .Times(1);

    EXPECT_CALL(*go2, MoveBy(_, _, _))
        .Times(1);

    EXPECT_CALL(*go3, MoveBy(_, _, _))
        .Times(1);


    // Set up for the execution of actions
    GameObjectManager<MockGameObject> man;
    man.AddObject(go);
    man.AddObject(go2);
    man.AddObject(go3);

    // Execute actions
    man.MoveObjects(1.0f, 0.0f, 0.0f);
}
