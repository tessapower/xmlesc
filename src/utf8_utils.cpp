//
// Created by Tessa Power on 12/09/21.
//

#include "../include/utf8_utils.h"


uint8_t num_utf8_bytes(const uint8_t c) {
    uint8_t num_bytes = 1;
    for (uint8_t mask = 0x1 << 7; (mask & c && mask > 0x1 << 4); mask >>= 1) {
        num_bytes++;
    }

    return num_bytes;
}

Codepoint parse_utf8_codepoint(uint8_t const *const bytes) {
    Codepoint cp{};
    const uint8_t len = num_utf8_bytes(bytes[0]);
    cp.num_utf8_bytes = len;

    if (len == 1) {
        cp.codepoint = bytes[0];

        return cp;
    }

    uint8_t mask = 0b00111111;
    uint32_t codepoint = 0;
    for (auto i = len - 1; i > 0; --i) {
        // TODO: Comment this nicely
        const uint32_t tmp = bytes[i] & mask;
        codepoint |= tmp << 6 * (len - i - 1);
    }

    // TODO: Comment this nicely
    switch(len) {
        case 2:
            mask = 0b00011111;
            break;
        case 3:
            mask = 0b00001111;
            break;
        case 4:
            mask = 0b00000111;
            break;
        default:
            break;
    }
    const uint32_t tmp = bytes[0] & mask;
    codepoint |= tmp << (6 * (len - 1));

    cp.codepoint = codepoint;

    return cp;
}
