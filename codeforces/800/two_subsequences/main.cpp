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
    char m{'z'};
    LPI(i, 0, s.size(), 1) { m = min(m, s[i]); }
    string s1;
    string s2;
    LPI(i, 0, s.size(), 1) {
      if (s[i] == m && s1.size() == 0) {
        s1.PB(s[i]);
      } else {
        s2.PB(s[i]);
      }
    }
    cout << s1 << ' ' << s2 << '\n';
  }

  return 0;
}
