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
    char c;
    string s;
    cin >> n >> c >> s;
    int ops = 0;
    VI divs;
    int div = 2;
    LPI(i, 0, s.size(), 1) {
      if (s[i] != c) {
        while ((i + 1) % div == 0 && div <= n) {
          ++div;
        }
        if (find(divs.begin(), divs.end(), div) == divs.end()) {
          divs.PB(div);
          ++ops;
        }
      }
    }
    cout << ops << '\n';
    LPI(i, 0, divs.size(), 1) { cout << divs[i] << ' '; }
    if (ops != 0) {
      cout << '\n';
    }
  }

  return 0;
}
