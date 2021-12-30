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

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    unordered_map<int, bool> mp;
    unordered_map<int, bool> dup;
    unordered_map<int, bool> used;
    int dupl = 0;
    LPI(i, 0, n, 1) {
      cin >> arr[i];
      if (mp[arr[i]] == true) dup[arr[i]] = true, ++dupl;
      mp[arr[i]] = true;
    }
    LPI(i, 0, n, 1) {
      if (dup[arr[i]] == true && used[arr[i]] != true) {
        --dupl;
        used[arr[i]] = true;
        arr[i] *= -1;
      }
    }
    unordered_map<int, bool> diff;
    int ans = 0;
    LPI(i, 0, n, 1) {
      if (diff[arr[i]] != true) ++ans, diff[arr[i]] = true;
    }
    cout << ans << '\n';
  }

  return 0;
}
