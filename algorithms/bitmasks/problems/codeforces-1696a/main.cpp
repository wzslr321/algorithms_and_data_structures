#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

int n, z;

void solve() {
  cin >> n >> z;
  vector<int> arr(n);
  int ans = 0;
  rep(i, 0, n) cin >> arr[i], ans = max(ans, arr[i] | z);

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
