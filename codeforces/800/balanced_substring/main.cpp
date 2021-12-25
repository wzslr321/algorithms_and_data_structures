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
    string s;
    cin >> n >> s;
    int ii = -1, jj = -1;
    int i = 0;
    while (ii == -1 && i < n) {
      int a = 0, b = 0;
      LPI(j, i, n, 1) {
        if (s[j] == 'a')
          ++a;
        else
          ++b;
        if (a == b) {
          ii = i + 1;
          jj = j + 1;
          break;
        }
      }

      ++i;
    }
    cout << ii << ' ' << jj << '\n';
  }

  return 0;
}
