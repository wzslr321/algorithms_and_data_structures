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
    int arr[n];
    LPI(i, 0, n, 1) { cin >> arr[i]; }
    int ans = INT_MIN;

    bool used[3];
    int maxel = INT_MIN;
    LPI(i, 0, n, 1) {
      if (arr[i] % 3 == 0) used[2] = true;
      if (arr[i] % 3 == 1) used[0] = true;
      if (arr[i] % 3 == 2) used[1] = true;
      maxel = max(maxel, arr[i]);
    }

    ans = (maxel / 3) + maxel % 3;
    if (maxel % 3 == 2) --ans;
    if(maxel % 3 == 0 && used[0]) ++ans;
    if(maxel % 3 == 0 && used[1]) ++ans;

    cout << ans << '\n';
  }

  return 0;
}
