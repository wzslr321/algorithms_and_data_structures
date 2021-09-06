#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <string>

int getNamesCount() {
    std::cout << "How many names would you like to enter? ";
    int length{};
    std::cin >> length;

    return length;
}

int main() {
    auto length = getNamesCount();

    auto* names{new std::string[static_cast<unsigned long>(length)]{}};

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (auto i{0}; i < length; i++) {
        std::cout << "Enter name #" << i + 1 << " ";
        std::getline(std::cin >> std::ws, names[i]);
    }

    std::sort(names, names + length);

    std::cout << "Sorted array: \n";
    for (auto i{0}; i < length; i++) {
        std::cout << names[i] << '\n';
    }

    return EXIT_SUCCESS;
}
