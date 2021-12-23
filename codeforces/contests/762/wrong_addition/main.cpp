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
    string a, s;
    cin >> a >> s;
    size_t an = a.size();
    size_t sn = s.size();
    if (sn < an) {
      cout << "-1\n";
      continue;
    }
    string b;
    string ans = "";
    int j = 1;
    for (size_t i = an; i > 0; --i) {
      if (s[sn - j] < a[i]) {
        string curr = "";
        int snum = (int)s[sn - j] - 48;
        int anum = (int)a[i] - 48;
        cout << " ? " << snum << ' ' << anum << '\n';
        int diff = snum - anum; 
        curr += (char)diff + 48;
        b += curr;
        if (j < 1) {
          ans == "-1";
          break;
        }
        string needed = "";
        needed += s[sn - j];
        needed += s[sn - j - 1];
        if (curr != needed) {
          ans == "-1";
          break;
        }
        --i;
        j += 2;
      } else {
        int snum = (int)s[sn - j] - 48;
        int anum = (int)a[i] - 48;
        int diff = snum - anum; 
        char curr = (char)diff + 48;
        b += curr;
        if (curr != s[sn - j]) {
          ans == "-1";
          break;
        }

        ++j;
      }
    }
    if (ans == "-1")
      cout << ans << '\n';
    else
      cout << b << '\n';
  }

  return 0;
}
