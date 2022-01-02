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
  string tmp;
  getline(cin, tmp);
  int k, n, m;
  cin >> k >> n >> m;
  int arr[n];
  int barr[m];

  LPI(i, 0, n, 1) { cin >> arr[i]; }
  LPI(i, 0, m, 1) { cin >> barr[i]; }

  int i = 0, j = 0;
  VI ans;
  bool git = true;
  while (i != n || j != m) {
    if (i != n && arr[i] == 0)
      ans.PB(0), ++k, ++i;
    else if (j != m && barr[j] == 0)
      ans.PB(0), ++k, ++j;
    else if (i != n && arr[i] <= k)
      ans.PB(arr[i++]);
    else if (j != m && barr[j] <= k)
      ans.PB(barr[j++]);
    else {
      git = false;
      break;
    }
  }

  if (!git) {
    cout << "-1\n";
  } else {
    for (auto el : ans)
      cout << el << ' ';
    cout << '\n';
  }
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
