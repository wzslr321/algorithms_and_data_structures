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

ll l, r;

auto solve() -> void {
  cin >> l >> r;
  if (r - l + 1 < 3) {
    cout << -1 << '\n';
    return;
  }

  if (!(l & 1)) {
    cout << l << ' ' << l + 1 << ' ' << l + 2 << '\n';
    return;
  }
  if (r - l + 1 > 3) {
    cout << l + 1 << ' ' << l + 2 << ' ' << l + 3 << '\n';
    return;
  }

  cout << -1 << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
