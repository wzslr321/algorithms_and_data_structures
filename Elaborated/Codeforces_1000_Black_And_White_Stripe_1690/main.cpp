#include <iostream>

using namespace std;

int n, k;
string s;

auto solve() -> void {
    cin >> n >> k >> s;

    int ans = 0;

    for (int i = 0; i < k; ++i) {
        if (s[i] == 'W') ++ans;
    }

    int i = 1, j = k;
    auto last = ans;
    while (j < n) {
        last += s[i - 1] == 'B' && s[j] == 'W';
        last -= s[i - 1] == 'W' && s[j] == 'B';
        ans = min(last, ans);

        ++i, ++j;
    }

    cout << ans << '\n';
}

auto main() -> int {
    int test_cases;
    cin >> test_cases;

    while (test_cases--)
        solve();

    return 0;
}
