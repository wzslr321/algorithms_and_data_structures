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
    string s;
    cin >> n >> s;
    int mini = INT_MAX;
    bool git = false;
    LPI(i, 0, n, 1) {
      if (s[i] == 'a') {
        auto szukaj = solve(s, i, git);
        if (git) {
          mini = szukaj;
          break;
        }
        mini = min(mini, solve(s, i, git));
      }
    }

    mini == INT_MAX ? cout << "-1\n" : cout << mini << endl;
  }

  return 0;
}
