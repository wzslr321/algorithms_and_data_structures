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
  int n, m, r, c;
  cin >> n >> m >> r >> c;
  string arr[n];
  bool can = false;
  LPI(i, 0, n, 1) { cin >> arr[i]; }
  LPI(i, 0, n, 1) {
    LPI(j, 0, m, 1) {
      if (arr[i][j] == 'B') {
        can = true;
        break;
      }
    }
    if (can) {
      break;
    }
  }
  if (!can) {
    cout << -1 << '\n';
    return;
  }
  if (arr[r - 1][c - 1] == 'B') {
    cout << "0\n";
    return;
  }
  int ans = -1;
  LPI(i, 0, m, 1) {
    if (arr[r - 1][i] == 'B') {
      ans = 1;
      break;
    }
  }
  if (ans == -1) {
    LPI(i, 0, n, 1) {
      if (arr[i][c - 1] == 'B') {
        ans = 1;
        break;
      }
    }
  }
  ans == 1 ? cout << "1\n" : cout << "2\n";
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
