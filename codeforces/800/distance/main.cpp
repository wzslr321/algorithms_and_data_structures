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
    int x1 = 0, x2, y1 = 0, y2;
    cin >> x2 >> y2;
    int d = abs(x1 - x2) + abs(y1 - y2);
    int c1 = 0, c2 = 0;
    int r1 = -1;
    int r2 = -1;
    LPI(i, 0, max(x2, y2) + 1, 1) {
      LPI(j, 0, max(x2, y2) + 1, 1) {
        int da = abs(x1 - i) + abs(y1 - j);
        int db = abs(x2 - i) + abs(y2 - j);
        if (d / 2 == da && d / 2 == db) {
          r1 = i;
          r2 = j;
          break;
        }
      }
    }

    cout << r1 << ' ' << r2 << '\n';
  }

  return 0;
}
