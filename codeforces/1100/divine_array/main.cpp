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

void scan(VI nums, int k, int x) {
    LPI(i, 0, k, 1) {
        unordered_map<int, int> v{};
        LPI(j, 0, nums.size(), 1) {
            if (v[nums[j]] == 0) {
                v[nums[j]] = 1;
            } else {
                v[nums[j]] += 1;
            }
        }
        LPI(j, 0, nums.size(), 1) { nums[j] = v[nums[j]]; }
        // cout << "SIZE: " << nums.size() << '\n';

        // LPI(j, 0, nums.size(), 1) { cout << nums[j] << ' '; }
        // cout << '\n';
    }

    cout << nums[x - 1] << '\n';
}
auto main() -> int {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t > 0) {
        int n, q;
        VI nums;
        cin >> n;
        bool perf{true};
        int an1;
        cin >> an1;
        nums.PB(an1);
        LPI(i, 1, n, 1) {
            int an;
            cin >> an;
            if (nums[i - 1] != an) {
                perf = false;
            }
            nums.PB(an);
        }
        cin >> q;
        while (q > 0) {
            unsigned ll x{0}, k{0};
            cin >> x >> k;
            if (perf) {
                if (k > 0) {
                    cout << nums.size() << '\n';
                    --q;
                    continue;
                } else {
                    cout << nums[0] << '\n';
                    --q;
                    continue;
                }
            }
            if (k > n) {
                k = k % n;
            }
            scan(nums, k, x);
            --q;
        }

        --t;
    }

    return 0;
}
