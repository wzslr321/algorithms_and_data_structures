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
    int n;
    cin >> n;
    vector<int> vec(n);
    LPI(i, 0, n, 1) { cin >> vec[i]; }
    if (n == 1) {
      cout << vec[0] << '\n';
      continue;
    }
    sort(vec.begin(), vec.end());
    auto maks = vec.front();
    LPI(i, 1, n, 1) { maks = max(maks, vec[i] - vec[i - 1]); }

    cout << maks << '\n';
  }

  return 0;
}
