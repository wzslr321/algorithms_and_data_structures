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

bool checkIfFirstLetterIsGood(const char inputStChar, const char nameStChar) {
    if (inputStChar == nameStChar) {
        return true;
    }

    return false;
}

bool checkSize(const std::string& input, const std::string_view& name) {
    if (name.length() == input.length()) {
        return true;
    }
    return false;
}

bool checkIfNameExists(const std::string& input,
                       const std::string_view (&names)[8]) {
    for (const auto& name : names) {
        const auto isLengthOk{checkSize(input, name)};
        if (isLengthOk) {
            const auto isStLetterGood{
                checkIfFirstLetterIsGood(input[0], name[0])};
            if (isStLetterGood) {
                if (name == input) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    constexpr std::string_view names[]{"Alex",  "Betty", "Caroline", "Dave",
                                       "Emily", "Fred",  "Greg",     "Holly"};

    auto name{getUserNameInput()};

    auto doesNameExists{checkIfNameExists(name, names)};

    if (doesNameExists) {
        std::cout << name << " was found \n";
    } else {
        std::cout << name << " was not found \n";
    }

    return EXIT_SUCCESS;
}
