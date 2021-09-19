include(FetchContent)

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

add_executable(num_utf8_bytes_tests num_utf8_bytes_tests.cpp
               parse_utf8_codepoint_tests parse_utf8_codepoint_tests.cpp)

# Organise everything in include and src to build a library specific to utf8_utils
# target_link_libraries(num_utf8_bytes_tests PRIVATE utf8_utils gtest gtest_main)
target_link_libraries(num_utf8_bytes_tests PRIVATE gtest gtest_main)
