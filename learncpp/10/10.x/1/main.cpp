#include <iostream>

enum items { health_potion, torch, arrow };

uint_fast8_t countTotalItems() {
    uint_fast8_t itemsAmount{};
    return itemsAmount;
}

int main() {
    auto itemsAmount{countTotalItems()};

    std::cout << itemsAmount;
    return 0;
}
