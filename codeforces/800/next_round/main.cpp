#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, c) for (int i{a}; i < b; i += c)
#define LPD(i, a, b, c) for (int i{a}; i < b; i -= c)

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef INT_MIN
#define INT_MIN -2147483648
#endif
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807

#define ZEROS_B(x) __builtin_clz(x)
#define ZEROS_E(x) __builtin_ctz(x)

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int n, k;
    cin >> n >> k;

    multiset<int> mst;

    LPI(i, 0, n, 1) {
        int sc;
        cin >> sc;
        mst.insert(sc);
    }

    auto it = mst.end();
    int i{0};
    while (i < k) {
        --it;
        ++i;
    }

    auto x = count_if(mst.begin(), mst.end(),
                      [it](auto arg) { return arg >= *it && arg > 0; });
    cout << x << '\n';

    return 0;
}
