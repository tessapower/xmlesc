//
// Created by Tessa Power on 29/08/21.
//
#include <iostream>
#include <map>

#include "../esc_codes.cpp"

uint8_t num_utf8_bytes(uint8_t c);
uint32_t parse_utf8_codepoint(uint8_t chars[], uint8_t len);

int main(const int argc, const char *argv[]) {
    // Handle argc == 1
    // Handle argc > 2
    const char* first_arg = argv[1];
//    std::string esc_string = "";

    for (char* c = const_cast<char *>(first_arg); *c != '\0'; c += num_utf8_bytes(*c)) {
        uint8_t n = num_utf8_bytes(*c);
        uint8_t chars[n];
        for (auto i = 0; i < n; ++i) {
            chars[i] = *(c + i);
        }

        uint32_t codepoint = parse_utf8_codepoint(chars, n);
        // find codepoint in map
//        auto key = m.find(codepoint);

        // add to escaped string
//        if (key != m.end()) {
//            esc_string += m[codepoint];
//        } else {
//            esc_string += c;
//        }
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

uint32_t parse_utf8_codepoint(uint8_t chars[], uint8_t len) {
    uint32_t codepoint = 0;
    if (len == 1) {
        codepoint = chars[0];

        return codepoint;
    }
    uint8_t mask = 0b00111111;
    for (auto i = len - 1; i > 0; --i) {
        uint32_t tmp = chars[i] & mask;
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
    uint32_t tmp = chars[0] & mask;
    codepoint |= tmp << (6 * (len - 1));

    return codepoint;
}
