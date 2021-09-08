#include <array>
#include <cstdlib>
#include <iostream>
#include <string_view>

std::string getUserNameInput() {
    std::string input{};
    std::cout << "Enter a name\n";
    std::cin >> input;

    return input;
}

bool checkIfNameExists(std::string input, const std::string_view (&names)[8]) {
    for (auto name : names) {
        if (name == input) {
            return true;
        }
    }

    return false;
}

bool checkIfFirstLetterIsGood(std::string input,
                              const std::string_view (&names)[8]) {
    for (auto character : *names) {
        if (character == input[0]) {
            return checkIfNameExists(input, names);
        }
    }

    return false;
}

int main() {
    const std::string_view names[]{"Alex",  "Betty", "Caroline", "Dave",
                                   "Emily", "Fred",  "Greg",     "Holly"};

    auto name{getUserNameInput()};

    bool doesNameExists{checkIfNameExists(name, names)};

    if (doesNameExists) {
        std::cout << name << " was found \n";
    } else {
        std::cout << name << " was not found \n";
    }

    return EXIT_SUCCESS;
}
