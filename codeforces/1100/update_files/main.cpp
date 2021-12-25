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
    auto n{0LL}, k{0LL};
    cin >> n >> k;
    auto i{1LL};
    auto sum{2LL};
    while (sum < n) {
      sum += min({sum, n, k});
      if (sum > k) {
        ++i;
        i += (n - sum + k - 1) / k;
        break;
      } else {
        ++i;
      }
    }
    n == 1 ? cout << "0\n" : n == 2 ? cout << "1\n" : cout << i << '\n';
  }

  return 0;
}
