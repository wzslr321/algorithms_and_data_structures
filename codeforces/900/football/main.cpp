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

  string pl{};
  cin >> pl;

  auto cnt{1};

  LPI(i, 1, pl.size(), 1) {
    if (cnt == 7) {
      cout << "YES";
      return 0;
    }
    if (pl[i - 1] == pl[i]) {
      ++cnt;
    } else {
      cnt = 1;
    }
  }

  cnt >= 7 ? cout << "YES" : cout << "NO";

  return 0;
}
