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

  int n;
  cin >> n;
  auto cnt(0);
  LPI(i, 2, n + 1, 1) {
    auto div(0);
    LPI(j, 2, i, 1) {
      if (div > 2) break;
      if (isPrime(j) && i % j == 0) ++div;
    }
    if (div == 2) ++cnt;
  }
  cout << cnt << '\n';

  return 0;
}
