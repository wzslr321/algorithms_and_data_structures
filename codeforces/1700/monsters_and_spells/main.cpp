#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)
#define CZYT(n, arr)                                                           \
  for (int i = 0; i < n; ++i)                                                  \
  cin >> arr[i]

using VI = vector<int>;
using PI = pair<int, int>;

ll n;
const int N = 105;
ll monsters[N], health[N];

auto solve() -> void {
  cin >> n;
  LPI(i, 1, n + 1, 1) cin >> monsters[i];
  LPI(i, 1, n + 1, 1) cin >> health[i];

  ll ans = 0LL, prev = n;
  for (int i = n; i >= 1; i--) {
    if (monsters[i] - monsters[i - 1] >= health[i]) {
      int indp_need = monsters[i] - health[i];
      ans +=
          (monsters[prev] - indp_need + 1) * (monsters[prev] - indp_need) / 2;
      prev = i - 1;
    } else {
      health[i - 1] =
          max(health[i - 1], health[i] - (monsters[i] - monsters[i - 1]));
    }
  }
  cout << ans << '\n';
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
