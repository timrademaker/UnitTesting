#include "pch.h"

#define EXPECT_SAME(expected, actual) EXPECT_EQ(&expected, &actual)
#define EXPECT_NOT_SAME(notExpected, actual) EXPECT_NE(&notExpected, &actual)

TEST(TestExamples, IsNullTest)
{
    int* nullPtr = nullptr;
    int* notNullPtr = new int;

    std::unique_ptr<int> uniqueInt = std::make_unique<int>(1);
    std::shared_ptr<int> sharedInt = nullptr;

    EXPECT_FALSE(nullPtr);

    ASSERT_TRUE(uniqueInt);
    *uniqueInt += 1;

    EXPECT_FALSE(sharedInt);

    ASSERT_TRUE(notNullPtr);

    delete notNullPtr;
}

TEST(TestExamples, AreSame)
{
    int someInt = 0;
    int& someIntReference = someInt;
    int anotherInt = 0;

    EXPECT_EQ(&someInt, &someIntReference);
    EXPECT_NE(&someInt, &anotherInt);
}

TEST(TestExamples, AreEqual)
{
    EXPECT_FLOAT_EQ(1.0f, 1.0f);                // Without tolerance
    EXPECT_NEAR(1.0f, 1.1f, 0.2f);              // With tolerance
    EXPECT_STREQ("Text", "Text");               // Compare text
    EXPECT_STRCASEEQ("Text", "TEXT");           // Ignore case
    
    EXPECT_NE(1.0f, 2.0f);
    EXPECT_FALSE(std::abs(1.0f - 2.0f) < 0.1f);
    EXPECT_NE(true, false);
    EXPECT_STRNE("Text", "Different text");
}

TEST(TestExamples, AdditionalEqualityChecks)
{
    EXPECT_LT(1, 2);        // Less than (<)

    EXPECT_LE(1, 2);        // Less than or equal to (<=)
    EXPECT_LE(1, 1);        // Less than or equal to (<=)

    EXPECT_GT(2, 1);        // Greater than (>)

    EXPECT_GE(2, 1);        // Greater than or equal to (>=)
    EXPECT_GE(1, 1);        // Greater than or equal to (>=)
}

TEST(TestExamples, IsTrue)
{
    EXPECT_TRUE(true);
    EXPECT_TRUE(1 == 1);

    EXPECT_FALSE(false);
    EXPECT_FALSE(1 == 2);
}

TEST(TestExamples, ExceptionTest)
{
    auto lambda = [](int i = 0)
    {
        if (i == 0)
        {
            throw std::exception();
        }
        else if (i == 1)
        {
            throw std::overflow_error("Overflow");
        }
    };

    EXPECT_THROW(lambda(), std::exception);

    EXPECT_THROW(lambda(1), std::overflow_error);
}

TEST(TestExamples, AdditionalExceptionTest)
{
    auto lambda = [](int i = 0)
    {
        if (i == 0)
        {
            throw std::exception();
        }
        else if (i == 1)
        {
            throw std::overflow_error("Overflow");
        }
    };

    EXPECT_ANY_THROW(lambda());

    EXPECT_NO_THROW(lambda(2));
}

TEST(TestExamples, DISABLED_ForcedFail)
{
    FAIL() << "This test was failed for no reason!";
}