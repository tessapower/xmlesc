//
// Created by Tessa Power on 29/08/21.
//
#include <iostream>
#include <map>

static std::map<char, char> m {
    {'a', 'z'},
    {'b', 'y'},
    {'c', 'x'},
};

int main(const int argc, const char *argv[]) {
    const char* first_arg = argv[1];
    const char c = *first_arg;
    
    std::cout << m[c] << std::endl;

    return EXIT_SUCCESS;
}
