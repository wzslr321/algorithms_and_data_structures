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

auto solve() -> void {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> a(n);
  vector<int> b(n);
  LPI(i, 0, n, 1) {
    int cost;
    cin >> cost;
    a[i] = {cost, i};
  }
  sort(a.begin(), a.end());
  CZYT(n, b);
  LPI(i, 0, n, 1) {
    if (a[i].first <= k)
      k += b[a[i].second];
    else
      break;
  }

  cout << k << '\n';
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
