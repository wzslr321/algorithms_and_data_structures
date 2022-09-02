#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

constexpr int N = 107;

auto solve() -> void {
  int n;
  cin >> n;
  VI arr(N);
  bool ans = true;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  for (int i = 1; i < n; ++i) {
    if (arr[i] % arr[0] != 0) ans = false;
  }

  ans ? cout << "YES\n" : cout << "NO\n";
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
