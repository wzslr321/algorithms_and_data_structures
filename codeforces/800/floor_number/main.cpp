#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    double n, x;
    cin >> n >> x;
    if (n == x) {
      if (n <= 2) {
        cout << "1\n";
      } else {
        cout << "2\n";
      }
      continue;
    }
    n -= 2;
    cout << ceil(n / x) + 1 << '\n';
  }

  return 0;
}
