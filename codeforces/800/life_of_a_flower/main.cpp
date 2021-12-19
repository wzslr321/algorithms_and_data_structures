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
    int arr[n];
    LPI(i, 0, n, 1) { cin >> arr[i]; }
    if(arr[0]) ++ans;
    LPI(i, 1, n, 1) {
      if (arr[i] && arr[i - 1]) ans += 5;
      if (!arr[i] && !arr[i - 1]) {
        ans = -1;
        break;
      }
      if (arr[i] && !arr[i - 1]) ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}
