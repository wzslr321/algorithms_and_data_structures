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
  vector vst(n + 1, vector<bool>(n + 1));
  vector<int> l(n);
  vector<int> r(n);
  LPI(i, 0, n, 1) {
    cin >> l[i] >> r[i];
    vst[l[i]][r[i]] = true;
  }

  LPI(i, 0, n, 1) {
    LPI(j, l[i], r[i] + 1, 1) {
      if ((j == l[i] or vst[l[i]][j - 1]) and (j == r[i] or vst[j + 1][r[i]])) {
        cout << l[i] << ' ' << r[i] << ' ' << j << '\n';
        break;
      }
    }
  }
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
