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
    auto t{0};
    cin >> t;

    LPI(i, 0, t, 1) {
        auto n{0};
        VVI st{};
        cin >> n;
        LPI(j, 0, n, 1) {
            VI ds{};
            LPI(k, 0, 5, 1) {
                auto d{0};
                cin >> d;
                ds.PB(d);
            }
            st.PB(ds);
        }

        auto found{false};
        LPI(j, 0, 5, 1) {
            LPI(k, 0, 5, 1) {
                if (k != j) {
                    auto l{0}, r{0};
                    auto no{false};
                    LPI(y, 0, n, 1) {
                        if (st[y][j] == 1) ++l;
                        if (st[y][k] == 1) ++r;
                        if (st[y][j] == 0 && st[y][k] == 0) no = true;
                    }
                    if (l >= n / 2 && r >= n / 2 && !no) {
                        found = true;
                    }
                }
            }
        }

        found ? cout << "YES\n" : cout << "NO\n";
    }

    return 0;
}
