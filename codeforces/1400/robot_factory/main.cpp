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

vector<vector<bitset<4>>> bts{};

VI ews{};
VI sws{};

int go_right(int i, int j) {
    auto cnt{0};
    while (bts[i][j].test(2) == 0) {
        ++cnt;
        ++j;
    }
    return cnt;
}

int go_down(int i, int j) {
    auto cnt{0};
    while (bts[i][j].test(1) == 0) {
        ++cnt;
        ++i;
    }

    return cnt;
}

int count_room(int i, int j) {
    auto sz{0};
    // This is current data from ews and sws
    /* 
        1 0 1 0 0
        0 0 1 0 0
        0 1 0 1 0
        2 1 0 1 0
        ============
        3 0 0 1 1
        2 0 0 0 0
        1 1 0 1 0
        0 0 0 0 0
    */
}

int main() {
    auto n{0}, m{0};

    cin >> n >> m;

    LPI(i, 0, n, 1) {
        vector<bitset<4>> tmp{};
        LPI(j, 0, m, 1) {
            auto num{0};
            cin >> num;
            tmp.PB(num);
        }
        bts.PB(tmp);
    }

    LPI(i, 0, n, 1) {
        LPI(j, 0, m, 1) {
            ews.PB(go_right(i, j));
            sws.PB(go_down(i, j));
        }
    }

    return 0;
}
