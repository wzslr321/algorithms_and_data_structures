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

  string s;
  cin >> s;
  int big = 0;
  LPI(i, 0, s.size(), 1) {
    if (s[i] < 97) ++big;
  }
  if (big > s.size() / 2) {
    LPI(i, 0, s.size(), 1) {
      if (s[i] >= 97) s[i] -= 32;
    }
  } else {
    LPI(i, 0, s.size(), 1) {
      if (s[i] < 97) s[i] += 32;
    }
  }
  cout << s << '\n';

  return 0;
}
