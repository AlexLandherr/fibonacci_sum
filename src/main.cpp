#include "include/functions.h"
#include <iostream>
#include <stdexcept>
#include <limits>
#include <array>
#include <string>
#include <cstdlib>

/*
What is the sum of all even Fibonacci numbers less than 4,000,000?
*/

int main() {
    int64_t fibonacci_limit = 0;
    int mode_select = 0;
    std::array<int, 4> valid_modes = {0, 1, 2, 3};
    std::string human_readable_mode_select;

    while (true) {
        std::cout << "Select summation mode from list below:" << '\n';
        std::cout << "0. Sum of all Fibonacci number below limit provided." << '\n';
        std::cout << "1. Sum of all even Fibonacci number below limit provided." << '\n';
        std::cout << "2. Sum of all odd Fibonacci number below limit provided." << '\n';
        std::cout << "3. Exit program." << '\n';
        std::cout << "Enter one of the listed values: ";
        std::cin >> mode_select;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "\n\nThat's an invalid input! Please try again." << '\n';
        } else if (std::find(std::begin(valid_modes), std::end(valid_modes), mode_select) != std::end(valid_modes)) {
            if (mode_select == 3) {
                std::exit(EXIT_SUCCESS);
            }
            break;
        } else {
            std::cout << "\nInvalid mode select, try again!" << '\n';
        }
    }

    while (true) {
        std::cout << "Provide limit for Fibonacci summation: ";
        std::cin >> fibonacci_limit;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "\n\nThat's an invalid input! Please try again." << '\n';
        } else if (!(fibonacci_limit > std::numeric_limits<int64_t>::max() || fibonacci_limit < std::numeric_limits<int64_t>::min())) {
            break;
        } else {
            std::cout << "\nInvalid mode select, try again!" << '\n';
        }
    }

    switch (mode_select) {
        case 0: {
            human_readable_mode_select = "all";
            break;
        }
        case 1: {
            human_readable_mode_select = "all even";
            break;
        }
        case 2: {
            human_readable_mode_select = "all odd";
            break;
        }
        default: {
            human_readable_mode_select = "";
            break;
        }
    }

    try {
        std::cout << "The sum of " << human_readable_mode_select << " Fibonacci numbers less than " << fibonacci_limit << " is: " << func::fibonacci_sum(fibonacci_limit, mode_select) << '\n';
    } catch (const std::invalid_argument& ex) {
        std::cout << ex.what() << '\n';
    } catch (const std::exception& ex) {
        std::cout << ex.what() << '\n';
    }

    return 0;
}