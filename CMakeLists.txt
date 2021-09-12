cmake_minimum_required(VERSION 3.20)
project(xmlesc VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 14)

add_executable(xmlesc bin/main.cpp src/utf8_utils.cpp src/esc_codes.cpp)

include_directories(include)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()