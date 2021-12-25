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
    int n;
    cin >> n;
    vector<int> arr(n);
    LPI(i, 0, n, 1) { cin >> arr[i]; }
    int ans = 0;
    while (!is_sorted(arr.begin(), arr.end())) {
      for (int i = ans % 2; i + 1 < n; i += 2) {
        if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
      }
      ++ans;
    }
    cout << ans << '\n';
  }

  return 0;
}
