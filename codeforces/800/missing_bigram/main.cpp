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
      int n;
      cin >> n;
      string arr[n-2];
      LPI(i,0,n - 2,1) {
          cin >> arr[i];
      }
      char curr = arr[0][0];
      string ans = "";
      ans += curr;
      for(auto &el : arr) {
        if(el[0] != curr) ans += el;
        else ans += el[1];
        curr = el[1];
      }
      if(ans.size() < n ) {
          ans += 'a';
      }
      cout << ans << '\n';
  }

  return 0;
}
