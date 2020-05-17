#include "pch.h"

TEST(ExpectedExamples, ExampleTest)
{
    EXPECT_EQ(1, 2);
    ASSERT_TRUE(nullptr);
    EXPECT_EQ(2, 3);
}

TEST(ExpectedExamples, ExampleTest2)
{
    EXPECT_EQ(1, 2);
    EXPECT_EQ(2, 3);
    ASSERT_TRUE(nullptr);
}
