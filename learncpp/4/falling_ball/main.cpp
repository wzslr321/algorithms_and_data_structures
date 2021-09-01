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

// I know about SRP principle, but I think it is redundant here. 
// Splitting this function into two functions will require to pass 
// two the same arguments into two separate functions.
// distance varaible returned wouldn't be enough, since the
// message requires seconds variable too. This function is to trival too 
// use SRP, instead of it YAGNI and KISS is probably better option.
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


