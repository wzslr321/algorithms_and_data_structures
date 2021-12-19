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
    int n, k;
    ll x;
    cin >> n >> k >> x;
    string s;
    cin >> s;
    int ccnt = 0;
    for (char c : s) {
      if (c == '*') ++ccnt;
    }
    int maxb = x / (ccnt * k);
    int maxbr = x % (ccnt * k);
    string ans = "";
    LPI(i, 0, n, 1) {
      if (s[i] == '*') {
        if (maxb > 0) {
          LPI(i, 0, k, 1) { ans.PB('b'); }
          --maxb;
        } else {
          LPI(i, 0, maxbr, 1) { ans.PB('b'); }
          maxbr = 0;
        }
      } else {
        ans.PB('a');
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
