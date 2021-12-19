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
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int st;
    char stc;
    LPI(i, 0, n, 1) {
      if (s[i] != '?') {
        st = i;
        stc = s[i];
        break;
      }
    }
    if (n == 1) {
      if (s[0] == '?')
        cout << "B\n";
      else
        cout << s << '\n';
      continue;
    }
    if (s[0] == '?') {
      if (s[1] == 'B')
        s[0] = 'R';
      else {
        if (s[1] == 'R')
          s[0] = 'B';
        else {
          if (st % 2 == 0) {
            if (stc == 'B')
              s[0] = 'B';
            else
              s[0] = 'R';
          } else {
            if (stc == 'B')
              s[0] = 'R';
            else
              s[0] = 'B';
          }
        }
      }
    }
    LPI(i, 1, n, 1) {
      if (s[i] == '?') {
        if (s[i - 1] == 'R') {
          s[i] = 'B';
        } else {
          s[i] = 'R';
        }
      }
    }
    cout << s << '\n';
  }

  return 0;
}
