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
    string v1, v2;
    cin >> v1 >> v2;
    int ans = 0;
    LPI(i, 0, n, 1) {
      if (v1[i] == '0' && v2[i] == '1') {
        ++ans;
        continue;
      }
      if (i > 0) {
        if (v1[i - 1] == '1' && v2[i] == '1') {
          ++ans;
          v1[i - 1] = 'x';
          continue;
        }
      }
      if (i < n + 1) {
        if (v1[i + 1] == '1' && v2[i] == '1') {
          ++ans;
          v1[i + 1] = 'x';
          continue;
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
