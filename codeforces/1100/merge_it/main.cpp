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
  VI cnt(3);
  unordered_map<int, bool> needed;
  LPI(i, 0, n, 1) {
    int num;
    cin >> num;
    ++cnt[num % 3];
  }

  int ans = cnt[0];
  int merge = min(cnt[1], cnt[2]);
  ans += merge;
  cnt[1] -= merge, cnt[2] -= merge;
  ans += (cnt[1] + cnt[2]) / 3;

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
