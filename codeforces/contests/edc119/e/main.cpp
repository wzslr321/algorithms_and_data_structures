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
  vector<int> arr;
  unordered_map<int, vector<int>> mp;
  while (t--) {
    int q;
    cin >> q;
    if (q == 1) {
      int x;
      cin >> x;
      arr.PB(x);
      mp[x].PB(arr.size() - 1);
    } else {
      int x, y;
      cin >> x >> y;
      if (x == y) continue;
      for (int i = mp[x].size() - 1; i >= 0; --i) {
        mp[y].PB(mp[x][i]);
        arr[mp[x][i]] = y;
        mp[x].pop_back();
      }
    }
  }
  for (auto el : arr) {
    cout << el << ' ';
  }
  cout << '\n';

  return 0;
}
