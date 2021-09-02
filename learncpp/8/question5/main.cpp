#include <iostream>



/*
 * Another way, not only C++20 compatible. 
 *
template <typename T>
T add(T x, T y)
{
    return x + y;
}
*/

// C++20 compatible 
auto add(auto x, auto y) { 
    return x + y; 
}

int main() {
    std::cout << add(2, 3) << '\n';
    std::cout << add(1.2, 3.4) << '\n';

    return 0;
}
