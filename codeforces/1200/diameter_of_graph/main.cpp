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
    ll n, m, k;
    cin >> n >> m >> k;
    // needed edges to make it complete graph
    ll ntcp = n * (n - 1) / 2;
    // graph is complete, diameter is 1
    if (m == ntcp && k > 2) {
      cout << "Yes\n";
      continue;
    }
    // graph not complete, diameter is 2
    if (m < ntcp && m >= n - 1 && k > 3) {
      cout << "Yes\n";
      continue;
    }
    // diameter is 0
    if (n == 1 && m == 0 && k >= 2) {
      cout << "Yes\n";
      continue;
    }
    cout << "No\n";
  }

  return 0;
}
