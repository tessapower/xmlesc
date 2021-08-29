//
// Created by Tessa Power on 29/08/21.
//
#include <iostream>
#include <map>

#include "../esc_codes.cpp"

int num_utf8_continuation_bytes(std::string const& str);

int main(const int argc, const char *argv[]) {
    const char* first_arg = argv[1];
    std::string esc_string = "";



//    for (std::string c = *(first_arg); c != '\0'; c = *(++first_arg)) {
//        auto key = m.find(c);
//        if (key != m.end()) {
//            esc_string += m[c];
//        } else {
//            esc_string += c;
//        }
//    }

    std::cout << esc_string << std::endl;

    return EXIT_SUCCESS;
}

int num_utf8_continuation_bytes(std::string const& str) {

    return str;
}