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
    auto n{0};
    VVI st{};
    cin >> n;
    LPI(j, 0, n, 1) {
      VI ds{};
      LPI(k, 0, 5, 1) {
        auto d{0};
        cin >> d;
        ds.PB(d);
      }
      st.PB(ds);
    }

    auto found{false};
    LPI(j, 0, 5, 1) {
      LPI(k, 0, 5, 1) {
        if (k != j) {
          auto l{0}, r{0};
          auto no{false};
          LPI(y, 0, n, 1) {
            if (st[y][j] == 1) ++l;
            if (st[y][k] == 1) ++r;
            if (st[y][j] == 0 && st[y][k] == 0) no = true;
          }
          if (l >= n / 2 && r >= n / 2 && !no) {
            found = true;
          }
        }
      }
    }

    found ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}
