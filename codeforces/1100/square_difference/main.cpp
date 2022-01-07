#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

ll a, b, p, i;

auto solve() -> void {
  cin >> a >> b;
  if (a - b != 1) {
    cout << "NO\n";
    return;
  }
  ll sum = sqrt(a + b) + 1;
  for (p = 1, i = 2; i < sum; ++i)
    p &= (a + b) % i > 0;

  p ? cout << "YES\n" : cout << "NO\n";
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
