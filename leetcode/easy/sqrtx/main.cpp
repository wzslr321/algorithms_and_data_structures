#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int mySqrt(int x) {
    int n{0};
    while (x > n * n) {
        n++;
    }

    if (n * n > x) return n - 1;
    return n;
};

int main() {
    cout << mySqrt(0) << '\n';
    cout << mySqrt(1) << '\n';
    cout << mySqrt(4) << '\n';
    cout << mySqrt(8) << '\n';
    cout << mySqrt(1024) << '\n';

    return 0;
}
