#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
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
    if (s.size() == 1) {
      cout << s << '\n';
      continue;
    }
    string ans = "";
    LPI(i, 0, s.size(), 1) {
      if (i == 0) {
        if (s[1] != s[0]) {
          ans += s[0];
          continue;
        }
      } else {
        if (s[i] != s[i - 1] && i < s.size() + 1 && s[i] != s[i + 1] &&
            ans.find(s[i]) == string::npos) {
          ans += s[i];
          continue;
        }
      }
      int occ = 1;
      while (i < s.size() + 1 && s[i] == s[i + 1]) {
        ++occ;
        ++i;
      }
      if (occ % 2 != 0 && ans.find(s[i]) == string::npos) {
        ans += s[i];
      }
    }
    sort(ans.begin(), ans.end());
    cout << ans << '\n';
  }

  return 0;
}
