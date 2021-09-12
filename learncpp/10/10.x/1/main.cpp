#include <array>
#include <iostream>

enum Items { health_potion, torch, arrow};

std::array<int, 3> startingItems{2, 5, 10};

int countTotalItems() {
    int itemsAmount{};
    itemsAmount += startingItems[Items::health_potion];
    itemsAmount += startingItems[Items::torch];
    itemsAmount += startingItems[Items::arrow];

    return itemsAmount;
}

int main() {
    int itemsAmount{countTotalItems()};

    std::cout << itemsAmount << '\n' << startingItems[Items::torch] << '\n';
    return 0;
}
