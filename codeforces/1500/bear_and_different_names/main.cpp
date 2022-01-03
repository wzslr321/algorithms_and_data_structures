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
  int n, k;
  cin >> n >> k;
  VS arr(n - k + 1);
  vector<string> ans(n);
  string curr = "Aaa";
  LPI(i, 0, n, 1) {
    ans[i] = "Aa";
    ans[i][0] += i / 26;
    ans[i][1] += i % 26;
  }
  LPI(i, 0, n - k + 1, 1) {
    string ef;
    cin >> ef;
    if (ef == "NO") ans[i + k - 1] = ans[i];
  }

  for (auto &el : ans)
    cout << el << ' ';
  cout << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
