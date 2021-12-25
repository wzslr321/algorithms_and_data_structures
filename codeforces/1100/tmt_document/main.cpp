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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int m = n / 3;
    int tl[m];
    int tr[m];
    int mm[m];
    int found = 0;
    bool ans = true;
    int tc = 0, mc = 0;
    LPI(i, 0, n, 1) {
      if (s[i] == 'T')
        ++tc;
      else
        ++mc;
    }
    if (tc != 2 * mc) {
      cout << "NO\n";
      continue;
    }
    LPI(i, 0, n, 1) {
      if (s[i] == 'T') {
        tl[found] = i;
        ++found;
        if (found == m) break;
      }
    }
    found = 0;
    LPI(i, 0, n, 1) {
      if (s[i] == 'M') {
        mm[found] = i;
        if (mm[found] < tl[found]) {
          ans = false;
          break;
        }
        ++found;
        if (found == m) break;
      }
    }
    found = 0;
    LPI(i, tl[m - 1] + 1, n, 1) {
      if (s[i] == 'T') {
        tr[found] = i;
        if (tr[found] < mm[found]) {
          ans = false;
          break;
        }
        ++found;
        if (found == m) break;
      }
    }
    ans ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}
