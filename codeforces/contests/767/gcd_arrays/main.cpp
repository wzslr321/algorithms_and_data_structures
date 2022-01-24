#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

#define PB push_back

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)
#define CZYT(n, arr)                                                           \
  for (int i = 0; i < n; ++i)                                                  \
  cin >> arr[i]

using VI = vector<int>;
using PI = pair<int, int>;

int l, r, k;

auto solve() -> void {
  cin >> l >> r >> k;
  if (l == r) {
    if (l != 1)
      cout << "YES\n";
    else
      cout << "NO\n";

    return;
  }
  int odd = (r - l + 1) - (r / 2 - (l - 1) / 2);
  if (odd <= k)
    cout << "YES\n";
  else
    cout << "NO\n";
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
