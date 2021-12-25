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
    int n;
    string s;
    cin >> n >> s;
    string t = s;
    sort(t.begin(), t.end());
    VI is;
    LPI(i, 0, n, 1) {
      if (t[i] != s[i]) is.PB(i + 1);
    }
    if (is.size() == 0) {
      cout << "0\n";
      continue;
    }
    cout << "1\n";
    cout << is.size() << ' ';
    LPI(i, 0, is.size(), 1) { cout << is[i] << ' '; }
    cout << '\n';
  }

  return 0;
}
