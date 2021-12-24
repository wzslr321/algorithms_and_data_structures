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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<int> b(n);
    LPI(i, 0, n, 1) { cin >> a[i]; }
    LPI(i, 0, n, 1) { cin >> b[i]; }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());
    bool ans = true;
    LPI(i, 0, n, 1) {
      if (a[i] + b[i] > x) {
        ans = false;
        break;
      }
    }
    ans ? cout << "Yes\n" : cout << "No\n";
  }

  return 0;
}
