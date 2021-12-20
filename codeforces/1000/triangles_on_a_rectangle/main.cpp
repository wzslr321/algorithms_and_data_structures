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
    ll w, h, k;
    cin >> w >> h >> k;
    ll mint = INT_MAX, maxt = INT_MIN;
    LPI(i, 0, k, 1) {
      ll tmp;
      cin >> tmp;
      mint = min(tmp, mint);
      maxt = max(tmp, maxt);
    }
    ll k2;
    cin >> k2;
    ll minb = INT_MAX, maxb = INT_MIN;
    LPI(i, 0, k2, 1) {
      ll tmp;
      cin >> tmp;
      minb = min(tmp, minb);
      maxb = max(tmp, maxb);
    }
    ll k3, k4;
    cin >> k3;
    ll minl = INT_MAX, maxl = INT_MIN;
    LPI(i, 0, k3, 1) {
      ll tmp;
      cin >> tmp;
      minl = min(tmp, minl);
      maxl = max(tmp, maxl);
    }
    cin >> k4;
    ll minr = INT_MAX, maxr = INT_MIN;
    LPI(i, 0, k4, 1) {
      ll tmp;
      cin >> tmp;
      minr = min(tmp, minr);
      maxr = max(tmp, maxr);
    }

    ll ans = max({(maxt - mint) * h, (maxb - minb) * h, (maxl - minl) * w,
                  (maxr - minr) * w});
    cout << fixed << ans << '\n';
  }

  return 0;
}
