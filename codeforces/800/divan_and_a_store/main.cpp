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
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    ll sum = 0LL;
    ll ans = 0LL;
    VI nums(n);
    LPI(i, 0, n, 1) { cin >> nums[i]; }
    sort(nums.begin(), nums.end());
    LPI(i, 0, n, 1) {
      if (sum >= k) break;
      if (nums[i] >= l && nums[i] <= r && sum + nums[i] <= k) {
        ++ans;
        sum += nums[i];
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
