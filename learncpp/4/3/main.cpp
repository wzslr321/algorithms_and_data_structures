#include <iostream>

double getValue();

char getSign();

double calculateValues(double firstValue, double secondValue, char sign);

int main() {
    double firstValue{getValue()};
    double secondValue{getValue()};

    char sign{getSign()};

    double result{calculateValues(firstValue, secondValue, sign)};

    std::cout << firstValue << " " << sign << " " << secondValue << " is "
              << result << '\n';
    return 0;
}

double getValue() {
    std::cout << "Enter a double value: ";

    double input{};
    std::cin >> input;

    return input;
}

char getSign() {
    std::cout << "Enter one of the following: +, -, *, or /:";

    char sign{};
    std::cin >> sign;

    return sign;
}

double calculateValues(double firstValue, double secondValue, char sign) {
    double result{};

    switch (sign) {
        case '+':
            result = firstValue + secondValue;
            break;
        case '-':
            result = firstValue - secondValue;
            break;
        case '*':
            result = firstValue * secondValue;
            break;
        case '/':
            result = firstValue / secondValue;
            break;
        default:
            std::cout << "This is not a valid sign.";
            break;
    }

    return result;
}

