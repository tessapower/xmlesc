cmake_minimum_required(VERSION 3.20)
project(xmlesc VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_subdirectory(tests)
endif()

add_subdirectory(src)
add_subdirectory(app)
