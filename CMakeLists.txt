cmake_minimum_required(VERSION 3.20)
project(xmlesc VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 14)

add_executable(xmlesc bin/main.cpp src/utf8_utils.cpp include/utf8_utils.h src/esc_codes.cpp)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_subdirectory(tests)
endif()

add_library(utf8_utils STATIC ./src/utf8_utils.cpp)
