#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

using ll = long long;

int n;
ll h;
const int N = 109;
ll arr[N];

auto solve() -> void {
  cin >> n >> h;
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  ll l = 1, r = 1e18;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    ll sum = mid;
    for (int i = 0; i < n - 1; ++i)
      sum += min(mid, arr[i + 1] - arr[i]);
    sum < h ? l = mid + 1 : r = mid - 1;
  }

  cout << r + 1 << '\n';
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
