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
    unsigned ll n;
    cin >> n;
    unsigned ll o{0};
    unsigned ll z{0};
    LPI(i, 0, n, 1) {
      unsigned ll num;
      cin >> num;
      if (num == 1) ++o;
      if (num == 0) ++z;
    }

    o > 0 ? cout << (1LL << z) * o << '\n' : cout << 0 << '\n';
  }

  return 0;
}
