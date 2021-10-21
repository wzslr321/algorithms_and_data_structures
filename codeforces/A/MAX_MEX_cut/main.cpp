#include <bits/stdc++.h>

using namespace std;

#define ar array
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

    int t{};
    cin >> t;
    VI out;
    LPI(i, 0, t, 1) {
        int s{};
        cin >> s;
        string r1{};
        string r2{};
        cin >> r1 >> r2;
        int v {};
        LPI(i, 0, s, 1) {
            if (r1[i] ^ r2[i]) {
                v += 2;
                continue;
            }

            if (r1[i] & r2[i]) {
                if (r1[i] == '1') {
                    if (i + 1 < s) {
                        if (r1[i + 1] == '0' && r2[i + 1] == '0') {
                            v += 2;
                            ++i;
                            continue;
                        }
                    }
                } else {
                    if (i + 1 < s) {
                        if (r1[i + 1] == '1' && r2[i + 1] == '1') {
                            v += 2;
                            ++i;
                            continue;
                        }
                    }
                    v += 1;
                }
            }
        }
        out.PB(v);
    }

    LPI(i, 0, t, 1) { cout << out[i] << '\n'; }

    return 0;
}
