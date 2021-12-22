#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  int length[n];
  length[0] = s[0] - 'a' + 1;
  LPI(i, 1, n, 1) { length[i] = length[i - 1] + s[i] - 'a' + 1; }
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    --r;
    if (l == 0) {
      cout << length[r] << '\n';
    } else {
      cout << length[r] - length[l - 1] << '\n';
    }
  }

  return 0;
}
