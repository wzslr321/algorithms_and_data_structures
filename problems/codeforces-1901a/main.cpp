#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> arr(n);
  rep(i, 0, n) cin >> arr[i];
  int ans = -1;
  bool sx = false;
  for(int i = 1; i < n; i++) {
      if(i + 1 == x) sx = true;
      ans = max(ans, arr[i + (sx && i < n - 1)] - arr[i - 1]);
  }
  ans = max(ans, arr[0]);
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
