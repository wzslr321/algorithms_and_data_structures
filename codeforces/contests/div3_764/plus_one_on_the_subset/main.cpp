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

auto solve() -> void {
  int n;
  cin >> n;
  int arr[n];
  int maxi = INT_MIN;
  int mini = INT_MAX;
  LPI(i, 0, n, 1) {
    cin >> arr[i];
    maxi = max(arr[i], maxi);
    mini = min(arr[i], mini);
  }
  cout << maxi - mini << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
