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
    long long n{0}, x{0}, t{0};
    cin >> n >> x >> t;
    long long res(max(0LL, n - (t / x)) * (t / x) +
                  min(n - 1LL, (t / x - 1LL)) * min(n, (t / x)) / 2LL);

    cout << res << '\n';
  }

  return 0;
}
