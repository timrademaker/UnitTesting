#include "pch.h"

#define ASSERT_SAME(expected, actual) ASSERT_EQ(&expected, &actual)
#define ASSERT_NOT_SAME(notExpected, actual) ASSERT_NE(&notExpected, &actual)

TEST(AssertExamples, IsNullTest)
{
    int* nullPtr = nullptr;
    int* notNullPtr = new int;

    std::unique_ptr<int> uniqueInt = std::make_unique<int>(1);
    std::shared_ptr<int> sharedInt = nullptr;

    ASSERT_FALSE(nullPtr);
    ASSERT_TRUE(uniqueInt);
    ASSERT_FALSE(sharedInt);

    ASSERT_TRUE(notNullPtr);

    delete notNullPtr;
}

TEST(AssertExamples, AreSame)
{
    int someInt = 0;
    int& someIntReference = someInt;
    int anotherInt = 0;

    ASSERT_EQ(&someInt, &someIntReference);
    ASSERT_NE(&someInt, &anotherInt);
}

TEST(AssertExamples, AreEqual)
{
    ASSERT_FLOAT_EQ(1.0f, 1.0f);                // Without tolerance
    ASSERT_NEAR(1.0f, 1.1f, 0.2f);              // With tolerance
    ASSERT_STREQ("Text", "Text");               // Compare text
    ASSERT_STRCASEEQ("Text", "TEXT");           // Ignore case
    
    ASSERT_NE(1.0f, 2.0f);
    ASSERT_FALSE(std::abs(1.0f - 2.0f) < 0.1f);
    ASSERT_NE(true, false);
    ASSERT_STRNE("Text", "Different text");
}

TEST(AssertExamples, AdditionalEqualityChecks)
{
    ASSERT_LT(1, 2);        // Less than (<)

    ASSERT_LE(1, 2);        // Less than or equal to (<=)
    ASSERT_LE(1, 1);        // Less than or equal to (<=)

    ASSERT_GT(2, 1);        // Greater than (>)

    ASSERT_GE(2, 1);        // Greater than or equal to (>=)
    ASSERT_GE(1, 1);        // Greater than or equal to (>=)
}

TEST(AssertExamples, IsTrue)
{
    ASSERT_TRUE(true);
    ASSERT_TRUE(1 == 1);

    ASSERT_FALSE(false);
    ASSERT_FALSE(1 == 2);
}

TEST(AssertExamples, ExceptionTest)
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

    ASSERT_THROW(lambda(), std::exception);

    ASSERT_THROW(lambda(1), std::overflow_error);
}

TEST(AssertExamples, AdditionalExceptionTest)
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

    ASSERT_ANY_THROW(lambda());

    ASSERT_NO_THROW(lambda(2));
}

TEST(AssertExamples, DISABLED_ForcedFail)
{
    FAIL() << "This test was failed for no reason!";
}