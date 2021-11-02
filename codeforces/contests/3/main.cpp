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

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define ZEROS_B(x) __builtin_clz(x)
#define ZEROS_E(x) __builtin_ctz(x)

/*
template <typename T>
T GCD(T a, T b) {
    if (a == 0) return b;
    if (b == 0) return a;
    T az = ZEROS_E(a);
    T bz = ZEROS_E(b);
    T shift = MIN(az, bz);
    b >>= bz;
    while (a != 0) {
        a >>= az;
        T diff = b - a;
        az = ZEROS_E(diff);
        b = MIN(a, b);
        a = std::abs(diff);
    }

    return b << shift;
}
*/


// it doesn't work
// i also share failures though

bool find(int a, VI b) {
    if (b[b.size() - 1] > a) {
        b.pop_back();
        return find(a, b);
    }
    int cr{0};
    while (b.size() > 0) {
        int last = b.size() - 1;
        while (cr + b[last] < a) {
            cr += b[last];
        }
        if (cr == a) return true;
        b.pop_back();
        return find(a - cr, b);
    }
    if(cr == a) return true;
    return false;
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
        int n, k, nc;
        cin >> n >> k;
        VI b{};
        LPI(i, 0, n, 1) {
            int bi;
            cin >> bi;
            if (bi == 0) bi = 1;
            b.PB(bi * 10);
        }
        int lkf{b[0] * k};
        while (find(lkf, b)) ++lkf;
        cout << lkf;
    }

    return 0;
}
