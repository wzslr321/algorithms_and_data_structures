#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

int n;

auto solve() -> void {
  cin >> n;
  if (n < 0) {
    n *= -1;
  }
  int ans = 0;
  if (n == 2) {
    ans = 1;
    cout << ans << '\n';
    return;
  }
  if (n % 3 == 0) ans = n / 3;
  // 2 -> 5
  if (n % 3 == 1 || n % 3 == 2) {
    ans = (n / 3) + 1;
    if (static_cast<int>(ceil(n / 3.) == 1)) ++ans;
  }
  cout << ans << '\n';
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
