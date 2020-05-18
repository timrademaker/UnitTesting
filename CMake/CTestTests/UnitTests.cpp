#include <stdexcept>
#include <assert.h>

#include "inc/TestHelpers.h"

void FunctionToTest(int i = 0)
{
    if (i == 0)
    {
        throw std::exception("Oh no, an exception!");
    }
    else if (i == 1)
    {
        throw std::overflow_error("Overflow or something");
    }
}

int main()
{
    const bool shouldFail = false;

    ASSERT_THROW(FunctionToTest(1), std::overflow_error);

    int i = 0;
    int& j = i;

    int k = 1;

    ASSERT_SAME(i, j);

    ASSERT_EQ(1, 1);
    

    if (!shouldFail)
    {
        return 0;
    }
    else
    {
        ASSERT_THROW(FunctionToTest(0) , std::overflow_error)
        ASSERT_SAME(i, k);
        ASSERT_EQ(1, 2);
        return 1;
    }
}