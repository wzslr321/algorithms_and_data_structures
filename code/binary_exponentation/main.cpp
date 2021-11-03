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
        a = a * a;
        b >>= 1;
    }
    return res;
}

auto main() -> int {
    cout << binary_exponentation_recursive(9, 16) << '\n';
    cout << binary_exponentation(9, 16) << '\n';

    return 0;
}
