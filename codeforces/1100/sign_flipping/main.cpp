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

const int N = 99;
int arr[N];
auto solve() -> void {
  int n;
  cin >> n;
  LPI(i, 0, n, 1) cin >> arr[i];
  LPI(i, 0, n, 2) {
    if (arr[i] > 0) arr[i] *= -1;
  }
  LPI(i, 1, n, 2) {
    if (arr[i] < 0) arr[i] *= -1;
  }
  LPI(i, 0, n, 1) cout << arr[i] << ' ';
  cout << '\n';
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
