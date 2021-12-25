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

  int n, s;
  cin >> n >> s;
  int v1[n], v2[n];
  LPI(i, 0, n, 1) { cin >> v1[i]; }
  LPI(i, 0, n, 1) { cin >> v2[i]; }

  if (v1[0] == 0) {
    cout << "NO\n";
    return 0;
  }
  if (v1[s - 1] == 1) {
    cout << "YES\n";
    return 0;
  }
  for (int i = s; i < n; ++i) {
    if (v1[i] == 1 && v2[i] == 1) {
      if (v2[s - 1] == 1) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
