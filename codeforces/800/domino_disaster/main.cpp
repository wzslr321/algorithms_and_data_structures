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
  unordered_map<char, char> m{{'U', 'D'}, {'D', 'U'}, {'L', 'L'}, {'R', 'R'}};
  while (t--) {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    LPI(i, 0, n, 1) { s2.PB(m[s1[i]]); }
    cout << s2 << '\n';
  }

  return 0;
}
