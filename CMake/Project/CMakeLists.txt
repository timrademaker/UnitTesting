set(SOURCES 
            src/main.cpp
)

set(HEADERS 
            inc/ITurtle.h
            inc/Painter.h
            inc/GameObject.h
            inc/GameObjectManager.h
)


add_executable(main_run ${SOURCES})

add_library(Project 
    STATIC
    ${HEADERS}
    ${SOURCES}
)

target_include_directories(Project PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc)

if(BUILD_TESTING)
    add_subdirectory(./testing)
endif(BUILD_TESTING)