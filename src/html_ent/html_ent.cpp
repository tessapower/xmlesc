//
// Created by Tessa Power on 24/09/21.
//

#include <utf8_utils/utf8_utils.h>
#include "esc_codes.cpp"

std::string escape(const std::string& input) {
    std::string esc_string;
    auto array = reinterpret_cast<const uint8_t *>(input.c_str());

    while(*array != '\0') {
        Codepoint cp = parse_utf8_codepoint(array);

        // find codepoint in map
        auto key = m.find(cp.codepoint);

        // add to escaped string
        if (key != m.end()) {
            esc_string += m[cp.codepoint];
        } else {
            esc_string += array[0];
        }

        array += cp.num_utf8_bytes;
    }

    return esc_string;
}
