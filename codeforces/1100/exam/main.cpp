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
  if (n == 1 || n > 3)
    cout << n << '\n';
  else
    cout << n - 1 << '\n';
  for (int i = n - 1; i > 0; i -= 2) {
    if (n == 3 || n == 2) break;
    cout << i << ' ';
  }
  for (int i = n; i > 0; i -= 2) {
    cout << i << ' ';
  }
}

// 1 6 2 5 3 4

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
