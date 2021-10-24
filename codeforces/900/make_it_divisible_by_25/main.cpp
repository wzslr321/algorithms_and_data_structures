#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

#define ZEROS_B(x) __builtin_clz(x)
#define ZEROS_E(x) __builtin_ctz(x)

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

const VS subseqs{"00", "25", "50", "75"};

int solve(string& s, string& t) {
    auto sb{s.length() - 1};

    auto ans{0};
    while (sb >= 0 && s[sb] != t[1]) {
        --sb;
        ++ans;
    }

    if (sb < 0) return INT_MAX;

    --sb;

    while (sb >= 0 && s[sb] != t[0]) {
        --sb;
        ++ans;
    }

    return sb < 0 ? INT_MAX : ans;
}

int main() {
    auto t{0};
    cin >> t;

    while (t--) {
        string n{};
        cin >> n;

        auto ans{INT_MAX};
        for (auto e : subseqs) ans = min(ans, solve(n, e));

        cout << ans << '\n';
    }

    return 0;
}
