set(HEADER_LIST "${xmlesc_SOURCE_DIR}/include/utf8_utils/utf8_utils.h")

add_library(utf8_utils STATIC utf8_utils.cpp ${HEADER_LIST})

target_include_directories(utf8_utils PUBLIC ../include)
target_include_directories(utf8_utils PRIVATE ../include/utf8_utils)
