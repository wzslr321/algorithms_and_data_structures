#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

#define PB push_back

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)
#define CZYT(n, arr)                                                           \
  for (int i = 0; i < n; ++i)                                                  \
  cin >> arr[i]

using VI = vector<int>;
using PI = pair<int, int>;

string s;

auto solve() -> void {
  cin >> s;
  size_t n = s.size();
  int good = 0;
  for (size_t i = 0; i < n - 1; ++i)
    if (s[i] - '0' + s[i + 1] - '0' >= 10) good = i;
  for (int i = 0; i < good; ++i)
    cout << s[i];
  cout << s[good] - '0' + s[good + 1] - '0';
  for (int i = good + 2; i < (int)n; ++i)
    cout << s[i];
  cout << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
