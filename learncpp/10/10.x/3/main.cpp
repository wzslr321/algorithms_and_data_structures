#include <iostream>

void swap(int& a, int& b) {
    int aval{a};
    std::cout << a << '\t' << b << '\n';
    a = b;
    b = aval;
    std::cout << a << '\t' << b << '\n';
}

int main() {
    int a{1};
    int b{2};
    swap(a, b);
    return 0;
}

