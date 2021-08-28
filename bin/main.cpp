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
    const char c = *first_arg;

    auto key = m.find(c);
    if (key != m.end()) {
        std::cout << m[c] << std::endl;
    } else {
        std::cout << c << std::endl;
    }

    return EXIT_SUCCESS;
}
