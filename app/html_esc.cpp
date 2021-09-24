//
// Created by Tessa Power on 29/08/21.
//
#include <iostream>
#include <map>

#include <html_ent/html_ent.h>

void print_help() noexcept;

int main(const int argc, const char *argv[]) {
    if (argc == 1 || argc > 2) {
        print_help();

        return EXIT_SUCCESS;
    }

    const std::string input = argv[1];
    std::cout << escape(input) << std::endl;

    return EXIT_SUCCESS;
}

void print_help() noexcept {
    std::cout << "Usage: html_esc \"html string to escape\"";
    std::cout << "\n\nExample:";
    std::cout << "\nhtml_esc \"<h1>Hello, World!</h1>\" -> &LT;h1&GT;Hello&comma; World&excl;&LT;&sol;h1&GT;\n";
}
