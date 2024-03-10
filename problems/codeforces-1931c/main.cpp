#include <bits/stdc++.h>

using namespace std;

int n;
constexpr int N = 2 * 1e5;
vector<int> arr(N);

auto solve() -> void {
  cin >> n;
  for(int i = 0; i < n; i++) cin >> arr[i];
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  int l = 1, r = 1;
  while (l < n - 1) {
    if (arr[l] != arr[l - 1]) 
      break;
    l++;
  }
  while (r < n - 1) {
    if (arr[n - r] != arr[n - r - 1])
      break;
    r++;
  }
  if (arr[0] == arr[n - 1]) {
    cout << max(0, n - r - l) << '\n';
  } else {
    cout << n - max(r, l) << '\n';
  }
}

auto main() -> int {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
