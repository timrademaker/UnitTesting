set(SOURCES 
            src/main.cpp
)


add_executable(main_run ${SOURCES})

add_library(Project 
    STATIC
    ${HEADERS}
    ${SOURCES}
)

target_include_directories(Project PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)