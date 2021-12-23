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

  int n;
  cin >> n;
  vector<int> arr(2 * n);
  LPI(i, 0, 2 * n, 1) { cin >> arr[i]; }
  int ans = 0;
  bool p2l = true;
  while (!is_sorted(arr.begin(), arr.end())) {
    if (!p2l && arr[0] < arr[1]) {
      LPI(i, 0, n, 1) { swap(arr[i], arr[n + i]); }
      p2l = true;
    } else {
      LPI(i, 0, (2 * n) - 1, 1) {
        swap(arr[i], arr[i + 1]);
        ++i;
      }
      p2l = false;
    }
    ++ans;
    if (ans > 2 * n) {
      ans = -1;
      break;
    }
  }

  cout << ans << '\n';

  return 0;
}
