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

bool solve(string s, int n) {
  if (n & 1) return false;
  int k = n / 2;
  LPI(i, 0, k, 1) {
    if (s[i] != s[i + k]) return false;
  }
  return true;
}

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
    auto n = s.size();
    solve(s, n) ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}
