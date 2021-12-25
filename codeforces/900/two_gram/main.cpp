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

  int n;
  cin >> n;
  string s;
  cin >> s;
  unordered_map<string, int> mp;
  int maxi = INT_MIN;
  string maxp;
  LPI(i, 0, n - 1, 1) {
    string str = "";
    str += s[i];
    str += s[i + 1];
    ++mp[str];
    int curr = mp[str];
    if (curr > maxi) {
      maxi = curr;
      maxp = str;
    }
  }
  cout << maxp << '\n';

  return 0;
}
