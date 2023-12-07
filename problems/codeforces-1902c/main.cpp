#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<ll> arr(n);
  unordered_map<int, int> seen;
  ll high = INT_MIN;
  rep(i, 0, n) cin >> arr[i], high = max(high, arr[i]);

  ll g = 0ll;
  rep(i, 0, n - 1) g = gcd(arr[i + 1] - arr[i], g);
  g = max(1ll, g);

  ll ans = 0;
  rep(i, 0, n) ans += (high - arr[i]) / g;

  ll add = n;
  sort(arr.begin(), arr.end());
  for (int i = n - 1; i > 0; i--) {
    if (arr[i - 1] + g < arr[i]) {
      add = (arr[n - 1] - arr[i]) / g + 1;
      break;
    }
  }

  cout << ans + add << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}


