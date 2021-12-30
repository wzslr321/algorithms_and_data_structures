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
    int ans = INT_MAX;
    if (rb > rd)
      ans = min(ans, 2 * n - rb - rd);
    else
      ans = min(ans, rd - rb);
    if (cb > cd)
      ans = min(ans, 2 * m - cb - cd);
    else
      ans = min(ans, cd - cb);
    cout << ans << '\n';
  }

  return 0;
}
