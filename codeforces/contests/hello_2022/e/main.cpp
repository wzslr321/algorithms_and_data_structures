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
  int n, m;
  cin >> n >> m;
  double smt = 0.;
  LPI(i, 0, n, 1) {
    double teacher;
    cin >> teacher;
    smt = max(teacher, smt);
  }
  LPI(i, 0, m, 1) {
    double k;
    cin >> k;
    ll sum = 0LL;
    double st[static_cast<size_t>(k)];
    LPI(j, 0, k, 1) {
      cin >> st[j];
      sum += st[j];
    }
    LPI(j, 0, k, 1) {
      double av = static_cast<double>((sum - st[j]) / k);
      //min cout << "AV: " << av << '\n';
      if (av > smt)
        cout << "0";
      else
        cout << "1";
    }
  }
  cout << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
