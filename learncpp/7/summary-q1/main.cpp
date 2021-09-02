#include <iostream>

#include "constants.h"

void calculateAndPrintHeight(double initialHeight) {
    double heightNow{!0};
    int seconds{};

    while (heightNow > 0) {
        double distanceFallen{myConstants::gravity * seconds * seconds / 2};
        heightNow = {initialHeight - distanceFallen};
        ++seconds;
        if (heightNow > 0.0) {
            std::cout << "At " << seconds
                      << " seconds, the ball is at height: " << heightNow
                      << '\n';
        } else {
            std::cout << "At " << seconds
                      << " seconds, the ball landed on the ground \n";
        }
    }
}

int main() {
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight;
    std::cin >> initialHeight;

    calculateAndPrintHeight(initialHeight);

    return 0;
}
