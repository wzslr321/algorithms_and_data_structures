#include <bits/stdc++.h>

using namespace std;

template <typename T>
T GCD(T a, T b) {
    if (a == 0) return b;
    if (b == 0) return a;
    T az = __builtin_ctz(a);
    T bz = __builtin_ctz(b);
    T shift = min(az, bz);
    b >>= bz;
    while (a != 0) {
        a >>= az;
        T diff = b - a;
        az = __builtin_ctz(diff);
        b = min(a, b);
        a = std::abs(diff);
    }

    return b << shift;
}

template <typename T>
T gcd(T a, T b) {
    if (!a || !b) return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

int main() {
    clock_t begin = clock();

    GCD(238237534534LL, 234823945235934LL);
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000
         << " ms\n";

    begin = clock();
    gcd(238237534534LL, 234823945235934LL);
    end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000
         << " ms\n";
}

