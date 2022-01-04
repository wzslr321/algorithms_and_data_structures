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
  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  if (n == 1) {
    cout << "1\n";
    return;
  }
  bool dupa = true;
  LPI(i, 1, n, 1) {
    if (s[i] != s[i - 1]) {
      dupa = false;
      break;
    }
  }
  if (dupa) {
    cout << n / k << '\n';
    return;
  }
  unordered_map<char, int> mp{};
  int ans = 0;
  int curr = 1;
  LPI(i, 1, n, 1) {
    while (i < n && s[i - 1] == s[i] && curr < k)
      ++curr, ++i;
    if (curr > 1 && curr != k) curr = 1;
    if (curr == k) {
      ++mp[s[i - 1]];
      curr = 1;
      ans = max(mp[s[i - 1]], ans);
    }
  }

  cout << ans << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
