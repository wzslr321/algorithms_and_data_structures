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

int n, val;
string s[200];

bool check(char x, char y) {
  val = (s[0][1] == y) + (s[1][0] == y) + (s[n - 1][n - 2] == x) +
        (s[n - 2][n - 1] == x);
  if (val <= 2) {
    cout << val << '\n';
    if (s[0][1] == y) cout << "1 2\n";
    if (s[1][0] == y) cout << "2 1\n";
    if (s[n - 1][n - 2] == x) cout << n << ' ' << n - 1 << '\n';
    if (s[n - 2][n - 1] == x) cout << n - 1 << ' ' << n << '\n';
    return true;
  }
  return false;
}

auto solve() -> void {
  cin >> n;
  LPI(i, 0, n, 1) cin >> s[i];
  if (check('0', '1'));
  else
    check('1', '0');
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
