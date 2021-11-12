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

template <typename T>
T LCM(T a, T b) {
    return a / GCD(a, b) * b;
}

int solve(const string& s, int in) {
    int a = 0;
    int b = 0;
    int c = 0;
    LPI(i, in, s.size(), 1) {
        if (s[i] == 'a') ++a;
        if (s[i] == 'b') ++b;
        if (s[i] == 'c') ++c;
        if (a > b && a > c) {
            if (a + b + c >= 2) return i - in + 1;
        }
    }
    return INT_MAX;
}

auto main() -> int {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

#ifndef ONLINE_JUDGE
    clock_t begin = clock();
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int mini = INT_MAX;
        LPI(i, 0, n, 1) {
            if (s[i] == 'a') mini = min(mini, solve(s, i));
            if (mini == 2) break;
        }

        mini == INT_MAX ? cout << "-1\n" : cout << mini << endl;
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000
         << " ms\n";
#endif

    return 0;
}
