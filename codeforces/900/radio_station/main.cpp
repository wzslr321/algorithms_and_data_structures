#pragma GCC optimize("Ofast,unroll-loops")

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

  int n, m;
  cin >> n >> m;
  unordered_map<string, string> mp;
  while (n--) {
    string s1, s2;
    cin >> s1 >> s2;
    mp[s2] = s1;
  }
  while (m--) {
    string s1, s2;
    cin >> s1 >> s2;
    string key = s2;
    key.pop_back();
    cout << s1 + ' ' + s2 + " #" + mp[key] << '\n';
  }

  return 0;
}
