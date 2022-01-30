cmake_minimum_required(VERSION 3.14)

project(taskman VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
# add_subdirectory(test)
add_subdirectory(examples)
add_subdirectory(source)
