#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

int n;
constexpr int N = 1e5 + 7;
vector<int> arr(N);

void solve() {
  cin >> n;
  rep(i, 0, n) cin >> arr[i];
  vector<ll> sums(n + 1, 0);
  for (int i = n - 1; i >= 0; i--)
    sums[i] = sums[i + 1] + arr[i];
  ll ans = sums[0];
  rep(i, 1, n) ans += sums[i] * (sums[i] > 0);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
