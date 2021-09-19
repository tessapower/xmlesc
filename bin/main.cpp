//
// Created by Tessa Power on 29/08/21.
//
#include <iostream>
#include <map>

#include "../src/esc_codes.cpp"
#include "../include/utf8_utils.h"

void print_help() noexcept;

int main(const int argc, const char *argv[]) {
    if (argc == 1 || argc > 2) {
        print_help();

        return EXIT_SUCCESS;
    }

    // Convert first arg pointer type from const char to const uint8_t
    const auto* input = (const uint8_t*)argv[1];
    std::string esc_string;

    while(*input != '\0') {
        Codepoint cp = parse_utf8_codepoint(input);

        // find codepoint in map
        auto key = m.find(cp.codepoint);

        // add to escaped string
        if (key != m.end()) {
            esc_string += m[cp.codepoint];
        } else {
            esc_string += input[0];
        }

        input += cp.num_utf8_bytes;
    }

    std::cout << esc_string << std::endl;

    return EXIT_SUCCESS;
}

void print_help() noexcept {
    std::cout << "Usage: xmlesc \"html string to escape\"";
    std::cout << "\n\nExample:";
    std::cout << "\nxmlesc \"<h1>Hello, World!</h1>\" -> &LT;h1&GT;Hello&comma; World&excl;&LT;&sol;h1&GT;\n";
}
