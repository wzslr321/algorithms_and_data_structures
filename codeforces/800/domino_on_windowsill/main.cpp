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
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;

    ((w <= (k1 + k2) / 2) && (b <= (n - k1 + n - k2) / 2)) ? cout << "YES\n"
                                                           : cout << "NO\n";

    --t;
  }

  return 0;
}
