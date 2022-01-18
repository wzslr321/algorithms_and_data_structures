#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

#define PB push_back

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)
#define CZYT(n, arr)                                                           \
  for (int i = 0; i < n; ++i)                                                  \
  cin >> arr[i]

using VI = vector<int>;
using PI = pair<int, int>;

int n;
ll k;
auto licz(vector<int> &arr, ll sum, ll &new_sum) -> ll {
  ll ans = 0LL;
  int i = 0, j = n - 1;
  while (sum > k && j > i) {
    sum -= abs(arr[j] - arr[i]);
    --j, ++ans;
  }
  new_sum = sum;
  return ans;
}

auto solve() -> void {
  cin >> n >> k;
  ll sum = 0LL;
  vector<int> arr(n);
  LPI(i, 0, n, 1) {
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr.begin(), arr.end());
  int dec = 0;
  ll new_sum = sum;
  auto ans = licz(arr, sum, new_sum);
  auto prev = ans;
  while (ans < prev || new_sum > k) {
    --arr[0], ++dec;
    prev = ans;
    --sum;
    auto curr = licz(arr, sum, new_sum) + dec;
    if (new_sum <= k) {
      ans = min(ans, curr);
    } else
      ans = curr;
  }

  if (new_sum > k) {
    cout << ans + new_sum - k << '\n';
  } else {
    cout << min(ans + dec, prev) << '\n';
  }
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
