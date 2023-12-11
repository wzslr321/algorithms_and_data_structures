#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> arr(n + 2);
  rep(i, 1, n + 1) cin >> arr[i];
  arr[n + 1] = x;
  int ans = -1;
  for (int i = 1; i <= n + 1; i++)
    ans = max(ans, arr[i] - arr[i - 1]);
  ans = max((arr[n + 1] - arr[n]) * 2, ans);

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
