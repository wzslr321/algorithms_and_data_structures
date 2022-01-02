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

auto solve() -> void {
  int n;
  cin >> n;
  string s;
  cin >> s;
  char prev = s[0];
  string curr = "";
  int currn = 0;
  LPI(i, 0, n, 1) {
    char c = s[i];
    if (c == '1') ++currn;
    if (c == '0' && c != prev) curr += (char)currn + 48, currn = 0;
    if (c == '0' && ((i < n - 1 && s[i + 1] == '0') || i == n - 1)) curr += c;
    prev = c;
    if (i == n - 1 && c == '1') curr += (char)currn + 48;
  }

  cout << curr << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
