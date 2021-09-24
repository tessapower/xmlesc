FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

add_executable(parse_codepoint parse_utf8_codepoint_tests.cpp)
add_executable(num_bytes num_utf8_bytes_tests.cpp)

target_link_libraries(parse_codepoint PRIVATE utf8_utils gtest gtest_main)
target_link_libraries(num_bytes PRIVATE utf8_utils gtest gtest_main)

add_test(NAME parse_codepoint COMMAND parse_codepoint)
add_test(NAME num_bytes COMMAND num_bytes)
