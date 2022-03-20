#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

int n, k;
constexpr int N = 107;
int arr[N];

auto solve() -> void {
  cin >> n >> k;
  for (auto i{0}; i < n; ++i)
    cin >> arr[i];

  auto i = 0;
  while (k > 0 && i < n - 1) {
    arr[i] > 0 ? --arr[i], --k, ++arr[n - 1] : ++i;
  }

  for (auto j{0}; j < n; ++j)
    cout << arr[j] << ' ';
  cout << '\n';
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
