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
    auto a{0}, b{0}, c{0};
    LPI(i, 0, s.size(), 1) {
      if (s[i] == 'A') ++a;
      if (s[i] == 'B') ++b;
      if (s[i] == 'C') ++c;
    }
    if (a + c == b) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
