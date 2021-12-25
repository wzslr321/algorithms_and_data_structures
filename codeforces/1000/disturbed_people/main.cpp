#pragma GCC optimize("Ofast,unroll-loops")

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

  int n;
  cin >> n;
  int arr[n];
  LPI(i, 0, n, 1) { cin >> arr[i]; }
  int ans = 0;
  LPI(i, 0, n, 1) {
    if (i > 0 && i < n - 1) {
      if (arr[i - 1] == 1 && arr[i] == 0 && arr[i + 1] == 1) {
        arr[i + 1] = 0;
        ++ans;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
