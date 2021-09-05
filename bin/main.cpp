//
// Created by Tessa Power on 29/08/21.
//
#include <iostream>
#include <map>

#include "../esc_codes.cpp"

uint8_t num_utf8_bytes(uint8_t c);
uint32_t parse_utf8_codepoint(uint8_t const * bytes, uint8_t * out_len);

int main(const int argc, const char *argv[]) {
    // Handle argc == 1
    // Handle argc > 2
    const auto* input = (const uint8_t*)argv[1];
//    std::string esc_string = "";

    while(*input != '\0') {
        uint8_t n = 0;
        uint32_t codepoint = parse_utf8_codepoint(input, &n);

//        // find codepoint in map
//        auto key = m.find(codepoint);
//
//        // add to escaped string
//        if (key != m.end()) {
//            esc_string += m[codepoint];
//        } else {
//            esc_string += c;
//        }

        input += n;
    }

//    std::cout << esc_string << std::endl;

    return EXIT_SUCCESS;
}


uint8_t num_utf8_bytes(const uint8_t c) {
    uint8_t num_bytes = 1;
    for (uint8_t mask = 0x1 << 7; (mask & c && mask > 0x1 << 4); mask >>= 1) {
        num_bytes++;
    }

    return num_bytes;
}

uint32_t parse_utf8_codepoint(uint8_t const *const bytes, uint8_t *const out_len) {
    const uint8_t len = num_utf8_bytes(bytes[0]);
    *out_len = len;

    uint32_t codepoint = 0;
    if (len == 1) {
        codepoint = bytes[0];

        return codepoint;
    }
    uint8_t mask = 0b00111111;
    for (auto i = len - 1; i > 0; --i) {
        uint32_t tmp = bytes[i] & mask;
        tmp <<= 6 * (len - i - 1);
        codepoint |= tmp;
    }

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
    uint32_t tmp = bytes[0] & mask;
    codepoint |= tmp << (6 * (len - 1));

    return codepoint;
}
