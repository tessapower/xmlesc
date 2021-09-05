//
// Created by Tessa Power on 29/08/21.
//
#include <iostream>
#include <map>

#include "../esc_codes.cpp"

uint8_t num_utf8_bytes(uint8_t c);

int main(const int argc, const char *argv[]) {
    const char* first_arg = argv[1];
//    std::string esc_string = "";

    num_utf8_bytes(0b11100101);

//    for (std::string c = *(first_arg); c != '\0'; c = *(++first_arg)) {
//        auto key = m.find(c);
//        if (key != m.end()) {
//            esc_string += m[c];
//        } else {
//            esc_string += c;
//        }
//    }

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
