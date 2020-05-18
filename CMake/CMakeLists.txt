cmake_minimum_required(VERSION 2.8.2)

project(ExampleProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

include(CTest)    # Doing this would automatically run enable_testing().
# enable_testing() # Can be used instead. Doesn't define BUILD_TESTING.

add_subdirectory(./Project)


if(BUILD_TESTING)
    add_subdirectory(./GoogleTestTests)
    add_subdirectory(./CTestTests)
endif(BUILD_TESTING)