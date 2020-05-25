add_library(Project_Test 
    INTERFACE
)

target_link_libraries(Project_Test INTERFACE Project)

target_include_directories(Project_Test INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})