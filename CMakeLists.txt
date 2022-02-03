cmake_minimum_required(VERSION 3.14)

project(taskman VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_library(${PROJECT_NAME} SHARED
            source/TaskMan.cpp
            # Getting these through a separate CMakeLists in the source dir would be more tidy.
            source/tasks/ThinkTask.cpp
            source/tasks/ThinkTask.h
            source/tasks/TaskFactory.h
            source/tasks/TaskFactory.cpp
            source/TaskController.h
            source/TaskController.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES
                      PUBLIC_HEADER "include/TaskMan.h;include/ITask.h")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Threads::Threads)

include_directories(${PROJECT_NAME} PRIVATE include)
include_directories(${PROJECT_NAME} PRIVATE source)
include_directories(${PROJECT_NAME} PRIVATE examples)

install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This could be toggled by a build variable
add_subdirectory(test)
add_subdirectory(examples)
