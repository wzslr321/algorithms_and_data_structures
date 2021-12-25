#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int mtr[n][m];
    auto mn(INT_MAX);
    auto sum(0);
    auto blw(0);
    LPI(i, 0, n, 1) {
      LPI(j, 0, m, 1) {
        cin >> mtr[i][j];
        if (mtr[i][j] < 0) ++blw;
        mn = min(mn, abs(mtr[i][j]));
        sum += abs(mtr[i][j]);
      }
    }
    blw & 1 ? cout << sum - 2 * mn << '\n' : cout << sum << '\n';
  }

  return 0;
}
