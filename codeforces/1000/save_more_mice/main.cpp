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

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    auto t{0};
    cin >> t;
    LPI(y, 0, t, 1) {
        auto n{0}, k{0}, cnt{0};
        cin >> n >> k;
        multiset<int, greater<int>> ms{};
        LPI(j, 0, k, 1) {
            auto tmp{0};
            cin >> tmp;
            ms.insert(tmp);
        }

        auto it{ms.begin()};
        auto mv{0};
        while (mv < n) {
            auto el{*it};
            while (el < n) {
                ++el;
                ++mv;
            }
            if (el == n) {
                ++cnt;
                ++it;
            }
        }

        cout << --cnt << '\n';
    }

    return 0;
}
