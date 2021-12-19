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

const int N = 500 * 1000 + 13;

int n;

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  unordered_map<int, vector<int>> mp;
  while (t--) {
    int q, x, y;
    cin >> q;
    if (q == 1) {
      cin >> x;
      mp[x].PB(n++);
    } else {
      cin >> x >> y;
      if (x != y) {
        if (mp[x].size() > mp[y].size()) mp[x].swap(mp[y]);
        for (auto i : mp[x])
          mp[y].PB(i);
        mp[x].clear();
      };
    }
  }
  int arr[n];
  LPI(i, 0, N, 1) {
    for (auto j : mp[i]) {
      arr[j] = i;
    }
  }
  for (auto el : arr)
    cout << el << ' ';
  cout << '\n';

  return 0;
}
