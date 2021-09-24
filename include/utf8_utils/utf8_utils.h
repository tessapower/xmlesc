//
// Created by Tessa Power on 12/09/21.
//

#ifndef UTF8_UTILS_H
#define UTF8_UTILS_H

#include <cstdint>

struct Codepoint {
    uint32_t codepoint;
    uint8_t num_utf8_bytes;
};

uint8_t num_utf8_bytes(uint8_t c) noexcept;
Codepoint parse_utf8_codepoint(uint8_t const * bytes) noexcept;

#endif //UTF8_UTILS_H
