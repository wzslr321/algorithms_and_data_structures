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

int a, b;

auto solve() -> void {
  cin >> a >> b;
  if (a > b) swap(a, b);
  int ans = 0;
  auto bc = a;
  auto diff = b - a;
  ans += diff / 3;
  a -= ans;
  b -= diff, b += diff % 3;
  ans += (a + b) / 4;
  cout << min(bc, ans) << '\n';
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
