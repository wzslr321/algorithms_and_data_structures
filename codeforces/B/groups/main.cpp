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

    int t{};
    cin >> t;

    LPI(i, 0, t, 1) {
        VS st{};
        int n{};
        cin >> n;

        int dv { n / 2 }
        if (dv % 2 != 0) {
            cout << "NO";
            return 0;
        }

        dv = 1;
        int tmp{--n};
        bool psb{};
        while (dv != tmp) {
            if (!(dv & 1) && !(tmp & 1)) {
                psb = true;
                break;
            }
            ++a;
            --w;
        }

        if (!psb) {
            cout << "NO";
            continue;
        }

        LPI(j, 0, n, 1) {
            string ds;
            LPI(k, 0, 5, 1) {
                char d;
                cin >> d;
                ds.push_back(d);
            }
            st.push_back(ds);
        }

        // let's say 14 groups
        // divide into 2 different
        // we need permutations of ranges which sum is equal 7
        // e.g. 1-7 and 7-14, 2-8 and 1-2 + 9-14
        // how tf am i suposed to do it
        // if i will manage to than compare ith days of group 1st
        // find on which index(es) i, & operand returns true, and save this index in VI
        // scan 2nd group, when proper index found, check if it doesn't collide with indexes from 1st group
        // if found index that doesn't collide - cout YES and return
        // if scan ended and no return happened - cout NO 
    }

    return 0;
}
