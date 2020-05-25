configure_file(GoogleTestDownload.txt googletest-download/CMakeLists.txt)

execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                 EXCLUDE_FROM_ALL)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

set(SOURCES 
    UnitTests.cpp 
    MoreUnitTests.cpp 
    PainterTests.cpp
    GameObjectTests.cpp
)

#foreach(test ${SOURCES})
#    string(FIND ${test} "." dotpos REVERSE)
#    string(SUBSTRING ${test} 0 ${dotpos} test_name)
#    string(CONCAT test_name ${test_name} "_gtest")
#
#    add_executable(${test_name} ${test})
#    target_compile_options(${test_name} PUBLIC ${GTEST_CFLAGS})
#    target_link_libraries(${test_name} ${GTEST_LDFLAGS})
#    target_link_libraries(${test_name} gtest gtest_main gmock gmock_main)
#    
#    target_link_libraries(${test_name} Project)
#    target_link_libraries(${test_name} Project_Test)
#    
#    target_include_directories( ${test_name}
#        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
#    )
#    
#    add_test(${test_name} ${test_name})
#endforeach()

set(test_name gtests)
add_executable(${test_name} ${SOURCES})
target_compile_options(${test_name} PUBLIC ${GTEST_CFLAGS})
target_link_libraries(${test_name} ${GTEST_LDFLAGS})
target_link_libraries(${test_name} gtest gtest_main gmock gmock_main)
    
target_link_libraries(${test_name} Project Project_Test)
    
target_include_directories( ${test_name}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
    
add_test(${test_name} ${test_name})