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
    string d;
    cin >> n >> d;
    int sum = 0;
    LPI(i, 0, n - 1, 1) {
      if (d[i] != '0') {
        sum += (int)d[i] - 47;
      }
    }
    if (d[n - 1] != '0') {
      sum += (int)d[n - 1] - 48;
    }
    cout << sum << endl;
  }

  return 0;
}
