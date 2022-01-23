#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

auto solve() -> void {
  int n;
  cin >> n;
  VI arr(n + 1);
  vector<VI> occ(n + 2);
  for (int i = 1; i <= n; ++i) {
    cin >> arr[i];
    occ[arr[i]].PB(i);
  }

  int l = 1;
  VI mexv;
  while (l <= n) {
    int mex = 0;
    int r = l;

    for (; mex <= n + 1; ++mex) {
      auto it = lower_bound(occ[mex].begin(), occ[mex].end(), l);
      if (it == occ[mex].end()) break;
      r = max(r, *it);
    }
    mexv.PB(mex);
    l = r + 1;
  }

  cout << mexv.size() << '\n';
  for (auto el : mexv)
    cout << el << ' ';
  cout << '\n';
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
