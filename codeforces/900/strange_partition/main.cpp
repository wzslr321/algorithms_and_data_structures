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
    ll x;
    cin >> n >> x;
    auto maks(0LL);
    long double mini(0LL);
    LPI(i, 0, n, 1) {
      long double val;
      cin >> val;
      maks += ceil(val / x);
      mini += val;
    }
    mini = ceil(mini / x);
    cout << fixed;
    cout << static_cast<ll>(mini) << ' ' << maks << '\n';
  }

  return 0;
}
