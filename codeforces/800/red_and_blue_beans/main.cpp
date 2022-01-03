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
  ll r, b, d;
  cin >> r >> b >> d;
  bool ans = true;
  // if (min(r, b) * (d + 1) >= max(r, b)) ans = false;
  if (b < r) swap(r, b);
  (b + d) / (d + 1) <= r ? ans = true : ans = false;
  ans ? cout << "YES\n" : cout << "NO\n";
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
