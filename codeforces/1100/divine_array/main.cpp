#pragma GCC optimize("Ofast,unroll-loops")

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

void scan(VI nums, int k, int an, VVI& qs) {
    if (k >= qs.size()) {
        if (k > qs.size()) k -= qs.size() - 1;
        LPI(i, 0, k, 1) {
            unordered_map<int, int> v{};
            LPI(j, 0, nums.size(), 1) {
                if (v[nums[j]] == 0)
                    v[nums[j]] = 1;
                else
                    v[nums[j]] += 1;
            }
            LPI(j, 0, nums.size(), 1) { nums[j] = v[nums[j]]; }
        }
        qs.PB(nums);
        cout << nums[an - 1] << '\n';
    } else {
        cout << qs[k][an - 1] << '\n';
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        VI nums;
        VVI qs;
        cin >> n;
        LPI(i, 0, n, 1) {
            int an;
            cin >> an;
            nums.PB(an);
        }
        qs.PB(nums);
        cin >> q;
        while (q--) {
            int x, k;
            cin >> x >> k;
            scan(nums, min(k, n), x, qs);
        }
    }

    return 0;
}
