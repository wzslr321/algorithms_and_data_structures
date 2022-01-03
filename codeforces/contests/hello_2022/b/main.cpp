#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

auto solve() -> void {
  int n;
  cin >> n;
  int l1 = INT_MAX;
  int r1 = INT_MIN;

  int lc = 0;
  int rc = 0;
  int ans = 0;
  LPI(i, 0, n, 1) {
    int l, r, c;
    cin >> l >> r >> c;
    if (l <= l1 || r >= r1) {
      if (l < l1 || (l == l1 && c < lc && r >= r1)) lc = c;
      if (r > r1 || (r == r1 && c < rc)) rc = c;
      if (l <= l1 && r >= r1) lc = c, rc = 0;
      ans = lc + rc;
      l1 = min(l, l1), r1 = max(r, r1);
    }
    cout << ans << '\n';
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
