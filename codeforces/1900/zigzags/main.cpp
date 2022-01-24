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
const int N = 3007;
int arr[N];
vector<int> freq(N *N, 0);

auto solve() -> void {
  cin >> n;
  CZYT(n, arr);
  ll ans = 0;
  // 1 3 3 1 2 3
  for (int j = n - 1; j >= 0; --j) {
    // j = 5, arr[j] = 3;
    int k = j + 1;

    // this executes when j <= 3;
    for (int l = k + 1; l < n; ++l) {
      // first iteration
      // k = 4; l = 5;
      // arr[k] = 2, arr[l] = 3;
      // freq[2 * 6 + 3(15)]++
      freq[arr[k] * n + arr[l]]++;
    }

    for (int i = 0; i < j; ++i)
      // first iteration
      // arr[i] = 1, arr[j] = 5; freq[30] = 0;
      total += freq[arr[i] * n + arr[j]];
  }

  cout << ans << '\n';
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
