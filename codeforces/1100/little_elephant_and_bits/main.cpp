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

string s;
bool del = false;
auto solve() -> void {
  cin >> s;
  LPI(i, 0, s.size(), 1) {
    if ((s[i] == '0' || i == static_cast<int>(s.size()) - 1) && !del) {
      del = true;
      continue;
    }
    cout << s[i];
  }
  cout << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
