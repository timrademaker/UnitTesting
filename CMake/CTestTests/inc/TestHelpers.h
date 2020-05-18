#pragma once

#include <assert.h>

#include <cstdio>

#define LOG_TEST_FAILURE() printf("Test failed!\nFile: %s\nLine: %i", __FILE__, __LINE__)

#define ASSERT_THROW(statement, expected_exception) \
    try \
    { \
    statement; \
    } \
    catch (expected_exception) \
    {} \
    catch (...) \
    { \
        throw; \
    }

#define ASSERT_ANY_THROW(statement) \
    { \
        bool caughtAny = false; \
        try { statement; } \
        catch (...) { caughtAny = true; } \
        if (!caughtAny) { assert(false && "No exception thrown while one was expected"); } \
    }

#define FAIL() \
    assert(false)

#define ASSERT_SAME(expected, actual) \
    assert(&expected == &actual)

#define ASSERT_EQ(expected, actual) \
    assert(expected == actual)