set(UTF8_HEADERS "${xmlesc_SOURCE_DIR}/include/utf8_utils/utf8_utils.h")
add_library(utf8_utils STATIC utf8_utils/utf8_utils.cpp ${UTF8_HEADERS})
target_include_directories(utf8_utils PUBLIC ../include)
target_include_directories(utf8_utils PRIVATE ../include/utf8_utils)

set(HTML_ENT_HEADERS "${xmlesc_SOURCE_DIR}/include/html_ent/html_ent.h" "${xmlesc_SOURCE_DIR}/include/html_ent/esc_codes.h")
add_library(html_ent STATIC html_ent/html_ent.cpp ${HTML_ENT_HEADERS})
target_link_libraries(html_ent PRIVATE utf8_utils)
target_include_directories(html_ent PUBLIC ../include)
target_include_directories(html_ent PRIVATE ../include/html_ent)
