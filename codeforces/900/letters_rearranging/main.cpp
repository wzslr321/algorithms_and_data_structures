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

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string s2 = "";
    bool same = true;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (i > 0)
        if (s[i] != s[i - 1]) same = false;
      s2 += s[i];
    }
    if (s2 != s) {
      cout << s << '\n';
      continue;
    }
    if (same) {
      cout << "-1\n";
      continue;
    }
    LPI(i, 0, s2.size() - 1, 1) {
      if (s2[i] != s2[i + 1]) swap(s2[i], s2[i + 1]);
    }
    cout << s2 << '\n';
  }

  return 0;
}
