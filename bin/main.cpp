//
// Created by Tessa Power on 29/08/21.
//
#include <iostream>
#include <map>

static std::map<char, std::string> m {
    {'<', "&lt;"},
    {'>', "&gt;"},
    {'&', "&amp;"},
    {'\'', "&apos;"},
    {'\"', "&quot;"},
};

int main(const int argc, const char *argv[]) {
    const char* first_arg = argv[1];
    std::string esc_string = "";

    for (char c = *(first_arg); c != '\0'; c = *(++first_arg)) {
        auto key = m.find(c);
        if (key != m.end()) {
            esc_string += m[c];
        } else {
            esc_string += c;
        }
    }

    std::cout << esc_string << std::endl;

    return EXIT_SUCCESS;
}
