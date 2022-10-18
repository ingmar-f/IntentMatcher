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
    src/GetWeatherCityIntent.cpp
    src/GetFactIntent.cpp
)

include(GoogleTest)

add_executable(tests
    src/tokenizer.cpp
    src/Intent.cpp
    src/IntentMatcher.cpp
    src/IntentFactory.cpp
    src/GetIntent.cpp
    src/GetWeatherIntent.cpp
    src/GetWeatherCityIntent.cpp
    src/GetFactIntent.cpp
    test/tokenizer_test.cpp
    test/matcher_test.cpp
)

target_link_libraries(
    tests
    GTest::gtest_main
)

gtest_discover_tests(tests)
