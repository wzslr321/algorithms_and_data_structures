#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

int n;
const int N = 200001;
int arr[N];
ll ans = 0LL;

auto solve() -> void {
  cin >> n;
  LPI(i, 0, n, 1) { cin >> arr[i]; }
  ans += abs(arr[0]);
  LPI(i, 1, n, 1) { ans += abs(arr[i] - arr[i - 1]); }
  cout << ans << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
