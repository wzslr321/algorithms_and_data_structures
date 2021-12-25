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
    ll x, n;
    cin >> x >> n;
    auto last = x + n - 2;
    auto sum = (x + last) / 2;
    if (n & 1) {
      sum -= n;
    } else {
      sum += n;
    }
    cout << sum << '\n';
  }

  return 0;
}
