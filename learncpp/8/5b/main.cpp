#include <iostream>

/*
template<typename T>
auto mult(T x, int y)
{
    return x * y;
}
*/

// Only C++ 20 compatible
auto mult(auto x, int y)
{
    return x * y;
}

int main()
{
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	return 0;
}
