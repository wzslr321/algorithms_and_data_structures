#include <bits/stdc++.h>

using namespace std;

using ll = long long;

auto binary_exponentation_recursive(ll a, ll b) -> ll {
    if (!b) return 1;
    ll res = binary_exponentation_recursive(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

auto binary_exponentation(ll a, ll b) -> ll {
    ll res = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a *= a;
        b >>= 1;
    }
    return res;
}

auto normal_pow(ll a, ll b) -> ll {
    ll res = 1;
    while (b > 0) {
        res *= a;
        --b;
    }

    return res;
}

auto modulo(ll a, ll b, ll m) -> ll {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1) res *= a % m;
        a *= a % m;
        b >>= 1;
    }
    return res;
}

#define LL_MAX 9223372036854775807

auto main() -> int {
    clock_t begin = clock();
    cout << binary_exponentation_recursive(LL_MAX, LL_MAX) << '\n';
    clock_t end = clock();
    cout << "\nExecuted in: " << double(end - begin) / CLOCKS_PER_SEC * 1000
         << " ms\n\n";

    cout << "--------------------\n";

    begin = clock();
    cout << binary_exponentation(LL_MAX, LL_MAX) << '\n';
    end = clock();
    cout << "\nExecuted in: " << double(end - begin) / CLOCKS_PER_SEC * 1000
         << " ms\n\n";

    cout << "--------------------\n";

    begin = clock();
    // ints here, 'cause probably noone have enough time to test it on so large
    // input
    cout << normal_pow(INT_MAX, INT_MAX) << '\n';
    end = clock();
    cout << "\nExecuted in: " << double(end - begin) / CLOCKS_PER_SEC * 1000
         << " ms\n";

    return 0;
}
