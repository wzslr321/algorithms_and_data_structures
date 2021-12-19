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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> np;
    vector<int> p;
    LPI(i, 0, n, 1) {
      int tmp;
      cin >> tmp;
      if (tmp & 1)
        np.PB(tmp);
      else
        p.PB(tmp);
    }
    LPI(i, 0, np.size(), 1) { cout << np[i] << ' '; }
    LPI(i, 0, p.size(), 1) { cout << p[i] << ' '; }
    cout << '\n';
  }

  return 0;
}
