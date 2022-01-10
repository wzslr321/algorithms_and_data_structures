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
  ll arr[n];
  vector<bool> matched(n);
  fill(matched.begin(), matched.end(), false);
  LPI(i, 0, n, 1) { cin >> arr[i]; }
  int git = 0;
  LPI(i, 0, n, 1) {
    while (arr[i] > 0) {
      if (arr[i] > n) {
        arr[i] /= 2;
      } else {
        if (!matched[arr[i]]) {
          ++git;
          matched[arr[i]] = true;
          break;
        }
        arr[i] /= 2;
      }
    }
  }
  if (git == n)
    cout << "YES\n";
  else
    cout << "NO\n";
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
