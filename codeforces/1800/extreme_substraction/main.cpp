#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

#define PB push_back

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)
#define CZYT(n, arr)                                                           \
  for (int i = 0; i < n; ++i)                                                  \
  cin >> arr[i]

using VI = vector<int>;
using PI = pair<int, int>;

int n;
const int N = 30007;
int arr[N];

auto solve() -> void {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  int w = 0;
  LPI(i, 2, n + 1, 1) {
    // 11 7 9 6 8
    // start: 7
    // w = 7 - 9, 9 - 6, 6 - 8; w = 3 -> we can dec 3 from bigger part
    // 11 7 9 6 8 ---> 8 4 6 6 8 (after 3 dec from left) // cleary can decrease
    // from here
    //
    // 1 3 1 3 1
    // w = 4 - we can barely touch these 3's
    //
    // 5 2 1 10
    // w = 1; we can dec once from left to make it -> 4 1 1 10
    w += max(arr[i - 1] - arr[i], 0);
  }
  if (w > arr[1])
    cout << "NO\n";
  else
    cout << "YES\n";
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
