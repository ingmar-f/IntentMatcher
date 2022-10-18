cmake_minimum_required (VERSION 3.22)
project (IntentMatcher)
find_package(GTest)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra -pedantic -Werror)
include_directories(src)

add_executable(match
    src/main.cpp
    src/tokenizer.cpp
    src/Intent.cpp
    src/IntentMatcher.cpp
    src/IntentFactory.cpp
    src/GetIntent.cpp
    src/GetWeatherIntent.cpp
)

include(GoogleTest)

add_executable(tokenizer_test
    src/tokenizer.cpp
    test/tokenizer_test.cpp
)

target_link_libraries(
    tokenizer_test
    GTest::gtest_main
)
gtest_discover_tests(tokenizer_test)
