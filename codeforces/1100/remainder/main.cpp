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

int n, x, y;
string s;

auto solve() -> void {
  cin >> n >> x >> y >> s;
  int ans = 0;
  for (int i = 0; i < x; ++i) {
    if ((s[n - 1 - i] != '0' && n - 1 - i != n - 1 - y) ||
        (n - 1 - y == n - 1 - i && s[n - 1 - i] == '0'))
      ++ans;
  }

  cout << ans << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
