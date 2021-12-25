#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int nums[n * k];
    LPI(i, 0, n * k, 1) { cin >> nums[i]; }
    ll sum = 0LL;
    int md = (n + 1) / 2 - 1;
    LPI(i, 1, k + 1, 1) { sum += nums[n * k - i * (n - md)]; }
    cout << sum << endl;
  }

  return 0;
}
