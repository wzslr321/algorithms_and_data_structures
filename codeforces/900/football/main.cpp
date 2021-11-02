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

    string pl{};
    cin >> pl;

    auto cnt{1};

    LPI(i, 1, pl.size(), 1) {
        if (cnt == 7) {
            cout << "YES";
            return 0;
        }
        if (pl[i - 1] == pl[i]) {
            ++cnt;
        } else {
            cnt = 1;
        }
    }

    cnt >= 7 ? cout << "YES" : cout << "NO";

    return 0;
}
