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


class SomeTestClass : public ::testing::Test
{
public:
    SomeTestClass() {}
private:
    virtual void TestBody();
    static ::testing::TestInfo* const test_info_;
};

::testing::TestInfo* const SomeTestClass::test_info_ =
    ::testing::internal::MakeAndRegisterTestInfo(
        "TheNameOfTheTestCase", "TheNameOfTheTest", NULL, NULL, 
        ::testing::internal::CodeLocation(__FILE__, __LINE__), 
        (::testing::internal::GetTestTypeId()),
        ::testing::Test::SetUpTestCase, 
        ::testing::Test::TearDownTestCase, 
        new ::testing::internal::TestFactoryImpl<SomeTestClass>);
void SomeTestClass::TestBody()
{

}