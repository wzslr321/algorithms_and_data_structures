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

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m, rb, cb, rd, cd;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int dirx = 1;
    int diry = 1;
    int ans = 0;
    while (rb != rd && cb != cd) {
      ++ans;
      if (rb + 1 > m) dirx = -1;
      if (rb - 1 < 0) dirx = 1;
      rb += dirx;
      if (cb + 1 > n) diry = -1;
      if (cb - 1 < 0) diry = 1;
      cb += diry;
    }

    cout << ans << '\n';
  }

  return 0;
}
