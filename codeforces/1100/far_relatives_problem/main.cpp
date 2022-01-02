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
  vector<PI> male;
  vector<PI> female;
  LPI(i, 0, n, 1) {
    char g;
    cin >> g;
    int key, val;
    cin >> key >> val;
    g == 'M' ? male.PB({key, val}) : female.PB({key, val});
  }
  int ans = INT_MIN;
  LPI(j, 1, 367, 1) {
    int m = 0, f = 0;
    for (auto &el : male)
      if (el.first <= j && el.second >= j) ++m;
    for (auto &el : female)
      if (el.first <= j && el.second >= j) ++f;
    ans = max(ans, 2 * min(m, f));
  }

  cout << ans << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
