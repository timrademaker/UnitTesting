#include "pch.h"


class TestEnvironment : public ::testing::Environment
{
public:
    ~TestEnvironment() override = default;

    void SetUp() override
    {
        printf("Test environment setup\n");
    }

    void TearDown() override
    {
        printf("Test environment teardown\n");
    }
};

class TestFixture : public ::testing::Test
{
protected:
    TestFixture()
    {
        printf("TestFixture constructor\n");
    }

    ~TestFixture()
    {
        printf("TestFixture destructor\n");
    }

    //static void SetUpTestSuite() // Google Test 1.10.0 and up
    static void SetUpTestCase()
    {
        sharedInt = 2;
        printf("Test fixture setup\n");
    }

    //static void TearDownTestSuite() // Google Test 1.10.0 and up
    static void TearDownTestCase()
    {
        printf("Test fixture teardown\n");
    }

    void SetUp() override
    {
        printf("Test method setup\n");
    }
    void TearDown() override
    {
        printf("Test method teardown\n");
    }

public:
    static int sharedInt;
};

int TestFixture::sharedInt = 1;

TEST_F(TestFixture, Test1)
{
    printf("Test1\n");
    ASSERT_EQ(sharedInt, 2); // Check if the setup actually ran
}

TEST_F(TestFixture, Test2)
{
    printf("Test2\n");
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::AddGlobalTestEnvironment(new TestEnvironment);

    return RUN_ALL_TESTS();
}