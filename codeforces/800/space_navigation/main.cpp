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
  int px, py;
  cin >> px >> py;
  string s;
  cin >> s;
  int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
  for (char c : s) {
    if (c == 'R') ++x1;
    if (c == 'L') --x2;
    if (c == 'U') ++y1;
    if (c == 'D') --y2;
  }

  bool ans = true;
  if (px < 0) {
    if (x2 > px) ans = false;
  } else {
    if (x1 < px) ans = false;
  }
  if (py < 0) {
    if (y2 > py) ans = false;
  } else {
    if (y1 < py) ans = false;
  }
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
