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

#define N = 1005;
int n;
int m;
// int time[N];
// int starts[N];
// int ends[N];

auto solve() -> void {
  cin >> n;
  int maxi = 0;
  LPI(i, 0, n, 1) {
    int num;
    cin >> num;
    maxi += num;
  }
  cin >> m;
  int ans = INT_MAX;
  int best = -1;
  LPI(i, 0, m, 1) {
    int left, right;
    cin >> left >> right;
    if (left <= maxi && right >= maxi) best = maxi;
    if (left > maxi) ans = min(left, ans);
  }
  if (ans == INT_MAX) ans = -1;

  best == -1 ? cout << ans << '\n' : cout << best << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
