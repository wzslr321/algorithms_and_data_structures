#include <cmath>
#include <iostream>

double getHeight();

void calculateAndPrintCurrentHeight(double height, double seconds);

int main() {
    double height{getHeight()};

    calculateAndPrintCurrentHeight(height, 0);
    calculateAndPrintCurrentHeight(height, 1);
    calculateAndPrintCurrentHeight(height, 2);
    calculateAndPrintCurrentHeight(height, 3);
    calculateAndPrintCurrentHeight(height, 4);
    calculateAndPrintCurrentHeight(height, 5);

    return 0;
}

double getHeight() {
    std::cout << "Enter the height of the tower in meters: ";

    double height{};
    std::cin >> height;

    return height;
}

void calculateAndPrintCurrentHeight(double height, double seconds) {
    constexpr double gravity = 9.8;
    double result{};

    result = (gravity * pow(seconds, 2.0)) / 2;
    double distance{};
    distance = height - result;

    if (distance > 0) {
        std::cout << "At " << seconds << ", the ball is at height: " << distance
                  << " meters \n";
    } else {
        std::cout << "At " << seconds << ", the ball is on the ground \n";
    }
}
