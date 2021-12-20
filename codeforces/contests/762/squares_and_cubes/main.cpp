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
    int n;
    cin >> n;
    int ans = 1;
    int ss = 2;
    int sc = 2;
    unordered_map<int, bool> used;
    while (pow(ss, 2) <= n) {
      ++ss;
      ++ans;
      used[pow(ss, 2)] = true;
    }
    while (pow(sc, 3) <= n) {
      if (!used[pow(sc, 3)]) ++ans;
      ++sc;
    }
    cout << ans << '\n';
  }

  return 0;
}
