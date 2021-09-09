#include <array>
#include <cstdlib>
#include <iostream>
#include <string_view>

/*
 * I know that those functions are totally useless
 * and string comparison shouldn't be done this way.
 * It is most-likely   a bad thing to overengineer a bad attitude
 * but I left it here, so I won't forget about it.
 * I wanted to split the tasks, assuming abstracly that string comparison
 * is not lazy and result is returned after check of every character
 * Just to train the thinking about the problem itself.
 * It is hopefully last time of this kind of this attitude,
 * since I should focus on real problems.
 */

std::string getUserNameInput() {
    std::string input{};
    std::cout << "Enter a name\n";
    std::cin >> input;

    return input;
}

bool checkIfNameExists(const std::string& input,
                       const std::string_view (&names)[8]) {
    for (const auto& name : names) {
        const auto isLengthOk{name.length() == input.length()};
        if (isLengthOk) {
            const auto isStLetterGood{input[0] == name[0]};
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
