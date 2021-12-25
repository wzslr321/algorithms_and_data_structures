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
    string s;
    cin >> s;
    int ans = -1;
    if (atoi(s.c_str()) % 2 == 0) {
      cout << "0\n";
      continue;
    }
    LPI(i, 0, s.size(), 1) {
      if (((int)s[i] - 48) % 2 == 0) {
        if (i == 0)
          ans = 1;
        else
          ans = 2;
        break;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
