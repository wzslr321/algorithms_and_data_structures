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

  int t{};
  cin >> t;
  VI out;
  LPI(i, 0, t, 1) {
    int s{};
    cin >> s;
    string r1{};
    string r2{};
    cin >> r1 >> r2;
    int v{};
    LPI(i, 0, s, 1) {
      if (r1[i] ^ r2[i]) {
        v += 2;
        continue;
      }

      if (i + 1 > s) {
        r1[i] == '0' ? ++val : out.PB(v);
        break;
      }

      if (r1[i] == '1') {
        if (r1[i + 1] == '0' && r2[i + 1] == '0') {
          v += 2;
          ++i;
          continue;
        }
        continue;
      }
      if (r1[i + 1] == '1' && r2[i + 1] == '1') {
        v += 2;
        ++i;
        continue;
      }
      v += 1;
    }
    out.PB(v);
  }

  LPI(i, 0, t, 1) { cout << out[i] << '\n'; }

  return 0;
}
