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

static bool was_left;
static bool was_right = true;
static bool changed_l;
static bool changed_r;

auto find(const string& s, const char c, int token) -> int {
    if (token < s.size() - 1) {
        if (s[token + 1] == c && !changed_l) {
            was_right = true;
            if (was_left) changed_r = true;
            return token + 1;
        }
    }
    if (token > 0) {
        if (s[token - 1] == c && !changed_r) {
            was_left = true;
            if (was_right) changed_l = true;
            return token - 1;
        }
    }

    return -2;
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
        string s1, s2;
        cin >> s1 >> s2;
        bool found{false};
        LPI(i, 0, s1.size(), 1) {
            if (s1[i] == s2[0]) {
                int valid = i;
                int in{1};
                while (valid != -2 && in != s2.size()) {
                    valid = find(s1, s2[in], valid);
                    if (valid != -2) {
                        ++in;
                    }
                }
                was_left = false;
                changed_r = false;
                changed_l = false;
                if (in == s2.size()) {
                    found = true;
                    break;
                }
            }
        }
        found ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
