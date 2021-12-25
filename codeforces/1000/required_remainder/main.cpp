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
    string s1;
    string s2;
    cin >> s1 >> s2;
    unordered_map<char, char> m;
    LPI(i, 0, s1.size(), 1) { m[s1[i]] = i; }
    char last = s2[0];
    auto s{0};
    LPI(i, 1, s2.size(), 1) {
      if (last == s2[i]) continue;
      s += fabs(m[last] - m[s2[i]]);
      last = s2[i];
    }
    cout << s << '\n';
  }

  return 0;
}
