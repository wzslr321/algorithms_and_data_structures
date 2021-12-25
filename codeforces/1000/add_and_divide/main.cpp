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
    int a, b;
    cin >> a >> b;
    int ops = 1e9;
    // log2(1e9) = 29
    if (b < 2) {
      ++ops;
      ++b;
    }
    int ah = a;
    int bh = b;
    while (b < 30) {
      int opsh = 0;
      if (b == 2) ++opsh;
      int es = ah;
      int ez = bh;
      while (es / ez > 1) {
        ++opsh;
        es /= ez;
        // cout << es / ez << ' ';
      }
      ++b;
      if (es == ez) opsh += 2;
      ops = min(ops, opsh);
    }
    cout << ops << endl;
  }

  return 0;
}
