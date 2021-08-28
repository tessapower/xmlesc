//
// Created by Tessa Power on 29/08/21.
//
#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
    char* first_arg = argv[1];
    char c = *first_arg;

    std::map<char, char> m { {'a', 'z'}, {'b', 'y'}, {'c', 'x'}, };

    std::cout << m[c] << std::endl;

    return EXIT_SUCCESS;
}