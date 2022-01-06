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
  if (n == 1) {
    cout << "1\n";
    return;
  }
  int arr[n];
  LPI(i, 0, n, 1) { cin >> arr[i]; }
  int ans = 0;
  LPI(i, 1, n, 1) {
    int j = i;
    while (arr[j] >= arr[j - 1] && j < n)
      ++j;
    int y = j;
    if (j != i) ++ans;
    while (arr[j] <= arr[j - 1] && j < n)
      ++j;
    if (j != y) ++ans;
    i = j - 1;
  }
  if (arr[1] < arr[0]) ++ans;
  cout << ans << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
