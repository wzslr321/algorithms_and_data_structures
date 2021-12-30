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
    string s;
    cin >> s;
    int i = 0;
    string ans = "";
    while (s[i] > s[i + 1] || (i != 0 && s[i + 1] == s[i]))
      ++i;
    ans = s.substr(0, i + 1);
    string rev = ans;
    reverse(rev.begin(), rev.end());
    ans += rev;
    cout << ans << '\n';
  }

  return 0;
}
