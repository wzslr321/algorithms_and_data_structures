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
    unordered_map<char, char> colors;
    string s;
    cin >> s;
    auto cnt{0};
    LPI(i, 0, s.size(), 1) {
      if (colors[s[i]] == 'r') {
        colors[s[i]] = 'b';
        ++cnt;
        continue;
      }
      if (colors[s[i]] == 'g') {
        colors[s[i]] = 'b';
        ++cnt;
        continue;
      }
      if (colors[s[i]] == 'b') continue;
      colors[s[i]] = 'r';
      ++cnt;
    }
    cout << cnt / 2 << '\n';
  }

  return 0;
}
