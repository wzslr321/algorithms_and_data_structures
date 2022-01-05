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
  int uno = 0;
  int dos = 0;
  LPI(i, 0, n, 1) {
    int tmp;
    cin >> tmp;
    if (tmp == 1)
      ++uno;
    else
      ++dos;
  }
  if ((uno + dos * 2) % 2 != 0) {
    cout << "NO\n";
  } else {
    int needed = (uno + dos * 2) / 2;
    if (needed % 2 == 0 || (needed % 2 == 1 && uno != 0)) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
