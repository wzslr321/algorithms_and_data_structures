#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

int n;

auto solve() -> void {
  cin >> n;
  vector<int> arr(n);
  vector<bool> numbers(n);
  for (int i = 0; i < n; ++i)
    cin >> arr[i];

  int diff_count = 0;
  for (int i = 0; i < n; ++i) {
    if (!numbers[arr[i]]) {
      ++diff_count;
      numbers[arr[i]] = true;
    }
  }

  if (diff_count == 1) diff_count = 0;
  if (diff_count == 0) {
    cout << 0 << '\n';
    return;
  }

  --diff_count;
  cout << min(diff_count, n / 2) << '\n';
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
