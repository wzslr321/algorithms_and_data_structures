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
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  LPI(i, 0, n, 1) {
    string s1, s2;
    cin >> s1 >> s2;
    int j = 0;
    bool ans = true;
    LPI(i, 0, s1.size(), 1) {
      if (s1[i] != s2[j]) {
        ans = false;
        break;
      }
      while (s1[i] == s2[j]) {
        ++j;
        if (i + 1 < s1.size() && s1[i + 1] == s2[j]) ++i;
      }
    }
    if (j < s2.size()) {
      LPI(i, s1.size(), s2.size(), 1) {
        if (s2[i] != s1.back()) {
          ans = false;
          break;
        }
      }
    }
    ans ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}
