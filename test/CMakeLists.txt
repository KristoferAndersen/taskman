
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

add_executable(some_test some_test.cpp)
target_link_libraries(some_test gtest_main)

include(GoogleTest)
gtest_discover_tests(some_test)
