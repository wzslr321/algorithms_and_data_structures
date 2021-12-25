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

  string s, t;
  cin >> s >> t;
  if (s.size() != t.size()) {
    cout << "No\n";
    return 0;
  }
  unordered_map<char, bool> vw{
      {'a', true}, {'e', true}, {'i', true}, {'o', true}, {'u', true},
  };
  bool ans = true;
  for (size_t i = 0; i < s.size(); ++i) {
    if (vw[s[i]] != vw[t[i]]) {
      ans = false;
      break;
    }
  }

  ans ? cout << "Yes\n" : cout << "No\n";

  return 0;
}
