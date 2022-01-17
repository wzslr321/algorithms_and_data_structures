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
  string k;
  cin >> k;
  ll sum = 0LL;
  ll ans = 0LL;
  for (auto ch : k) {
    if (ch == 'X') continue;
    sum += (ll)ch - 48LL;
    sum %= 999999990LL;
  }
  while (sum % 9)
    ++ans, ++sum;
  if ((k[0] == 'X' || k[0] == 'x') && ans == 0) ans = 9;
  cout << ans << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
