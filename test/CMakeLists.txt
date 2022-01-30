include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(TaskManTest
               TaskManTest.cpp)

target_link_libraries(TaskManTest gtest_main)
target_link_libraries(TaskManTest taskman)

include(GoogleTest)
gtest_discover_tests(TaskManTest)
