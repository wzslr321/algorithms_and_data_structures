#include <iostream>

int main() {
    const char* str{"Hello, world"};
    while(*str != '\0'){
        std::cout << *str << '\n';
        ++str;
    }

    return 0;
}
