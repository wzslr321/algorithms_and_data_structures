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

  int n, s;
  cin >> n >> s;
  int time[n];
  LPI(i, 0, n, 1) {
    int h, m;
    cin >> h >> m;
    time[i] = 60 * h + m;
  }

  if (time[0] >= s + 1) {
    cout << "0 0\n";
    return 0;
  }
  LPI(i, 0, n - 1, 1) {
    if (time[i + 1] - time[i] > 2 * s + 1) {
      cout << (time[i] + s + 1) / 60 << ' ' << (time[i] + s + 1) % 60 << '\n';
      return 0;
    }
  }

  cout << (time[n - 1] + s + 1) / 60 << ' ' << (time[n - 1] + s + 1) % 60
       << '\n';

  return 0;
}
