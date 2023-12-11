#pragma GCC optimize("O3")

#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

constexpr int N = 2 * 1e5 + 13;
int n;
vector<int> arr(N);

void solve() {
  cin >> n;
  rep(i, 0, n) cin >> arr[i];
  ll ans = 0;
  for (int i = n - 1; i > 0; i--) {
    ll k = (arr[i] + arr[i - 1] - 1) / arr[i];
    ans += k - 1;
    arr[i - 1] /= k;
  }
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
