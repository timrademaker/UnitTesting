set(SOURCES UnitTests.cpp MoreUnitTests.cpp)

foreach(test ${SOURCES})
    string(FIND ${test} "." dotpos REVERSE)
    string(SUBSTRING ${test} 0 ${dotpos} test_name)
    string(CONCAT test_name ${test_name} "_ctest")
    
    add_executable(${test_name} ${test})
    add_test(${test_name} ${test_name})
endforeach()