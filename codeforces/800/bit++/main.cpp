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

  int n;
  cin >> n;
  int ans = 0;
  LPI(i, 0, n, 1) {
    string s;
    cin >> s;
    if (s[1] == '+')
      ++ans;
    else
      --ans;
  }
  cout << ans << '\n';

  return 0;
}
