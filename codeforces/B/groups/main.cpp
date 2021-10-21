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
using USI = unordered_set<int>;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t{};
    cin >> t;
    vector<char> answers{};

    LPI(i, 0, t, 1) {
        VS st{};
        int n{};
        cin >> n;

        LPI(j, 0, n, 1) {
            string ds{};
            LPI(k, 0, 5, 1) {
                char d{};
                cin >> d;
                ds.PB(d);
            }
            st.PB(ds);
        }

        if (n % 2 != 0) {
            answers.PB('0');
            continue;
        }

        auto found{false};
        do {
            VI in{};
            LPI(j, 0, 5, 1) {
                bool ok{true};
                LPI(y, 0, n / 2, 1) {
                    if (st[y][j] == '0') {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    in.PB(j);
                }
            }
            LPI(j, 0, 5, 1) {
                bool ok{true};
                LPI(y, n / 2, n, 1) {
                    if (st[y][j] == '0') {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    for (const auto el : in) {
                        if (el != j) {
                            found = true;
                        }
                    }
                }
            }
        } while (next_permutation(st.begin(), st.end()));

        found ? answers.PB('1') : answers.PB('0');
    }

    LPI(i, 0, t, 1) { answers[i] == '1' ? cout << "YES\n" : cout << "NO\n"; }

    return 0;
}
