#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> q;
  cin >> s + 1;
  LPI(i, 1, n, 1) { ans += solve(i); }
  LPI(i, 0, q, 1) {
    int pos;
    char c;
    cin >> pos;
    cin >> c;
    ans -= solve(pos - 2) + solve(pos - 1) + solve(pos);
    s[pos] = c;
    ans += solve(pos - 2) + solve(pos - 1) + solve(pos);
    cout << ans << '\n';
  }

  return 0;
}
