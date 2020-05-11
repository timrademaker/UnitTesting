#include "pch.h"

bool IsEven(const int a_Number)
{
    return (a_Number % 2) == 0;
}

TEST(PredicateAssertions, AvoidThis)
{
    const int a = 1;
    EXPECT_TRUE(IsEven(a));
}

TEST(PredicateAssertions, AssertPredExample)
{
    const int a = 1;
    EXPECT_PRED1(IsEven, a);
}

struct SomeStruct
{
    int a = 0;
    bool b = false;

    friend std::ostream& operator<<(std::ostream& os, const SomeStruct& ss);
};

std::ostream& operator<<(std::ostream& os, const SomeStruct& ss)
{
    os << "a: " << ss.a << "\nb: " << ss.b;
    return os;
}

bool AEqualsZero(const SomeStruct& a_Struct)
{
    return a_Struct.a == 0;
}

TEST(PredicateAssertions, StructAssertPredExample)
{
    SomeStruct ss;
    ss.a = 1;
    EXPECT_PRED1(AEqualsZero, ss);
}

::testing::AssertionResult IsEvenAR(const int a_Number)
{
    if ((a_Number % 2) == 0)
    {
        return ::testing::AssertionSuccess();
    }
    else
    {
        return ::testing::AssertionFailure() << a_Number << " is odd";
    }
}

TEST(PredicateAssertions, AssertionResultExample)
{
    const int a = 1;
    EXPECT_TRUE(IsEvenAR(a));
}

::testing::AssertionResult IsEvenFormatted(const char* a_Number_Expression, const int a_Number)
{
    if ((a_Number % 2) == 0)
    {
        return ::testing::AssertionSuccess();
    }
    else
    {
        return ::testing::AssertionFailure() 
            << a_Number_Expression 
            << " (" << a_Number << ") is odd";
    }
}

TEST(PredicateAssertions, PredicateFormatterExample)
{
    const int a = 1;
    EXPECT_PRED_FORMAT1(IsEvenFormatted, a);
}

::testing::AssertionResult AEqualsZeroFormatted(const char* a_Struct_Expression, const SomeStruct& a_Struct)
{
    if (a_Struct.a == 0)
    {
        return ::testing::AssertionSuccess();
    }

    return ::testing::AssertionFailure()
        << a_Struct_Expression << "'s a (" << a_Struct.a << ") is not 0";
}

TEST(PredicateAssertions, StructPredFormatterExample)
{
    SomeStruct ss;
    ss.a = 1;
    EXPECT_PRED_FORMAT1(AEqualsZeroFormatted, ss);
}