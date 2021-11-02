#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

#define ll long long
#define ld long double
#define u unsigned

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i{a}; i < b; i += d)
#define LPD(i, a, b, d) for (int i{a}; i < b; i -= d)

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef INT_MIN
#define INT_MIN -2147483648
#endif
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;

#define ZEROS_B(x) __builtin_clz(x)
#define ZEROS_E(x) __builtin_ctz(x)

constexpr double pi = acos(-1);
constexpr int mod = 998244353;
constexpr double eps = 1e-10;
constexpr int N = 1e2 + 10;

template <typename T>
T GCD(T a, T b) {
    if (a == 0) return b;
    if (b == 0) return a;
    T az = ZEROS_E(a);
    T bz = ZEROS_E(b);
    T shift = min(az, bz);
    b >>= bz;
    while (a != 0) {
        a >>= az;
        T diff = b - a;
        az = ZEROS_E(diff);
        b = min(a, b);
        a = std::abs(diff);
    }

    return b << shift;
}

auto main() -> int {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll x, n;
        cin >> x >> n;
        if (n % 2 == 1) {
            auto res = x - n - 1LL + n;
            cout << res << '\n';
        } else {
            auto res = x + n - 1LL + n;
            cout << res << '\n';
        }
    }

    return 0;
}
