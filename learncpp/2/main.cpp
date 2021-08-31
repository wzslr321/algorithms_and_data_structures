#include <iostream>

int readNumber();

void writeAnswer(int number);

int main() {
    int x{readNumber()};
    int y{readNumber()};

    writeAnswer(x + y);

    return 0;
}

int readNumber() {
    int input{};
    std::cin >> input;

    return input;
}

void writeAnswer(int number) { std::cout << number << '\n'; }
