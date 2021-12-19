#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

#define ll long long
#define ld long double
#define u unsigned

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)
#define LPD(i, a, b, d) for (int i = a; i < b; i -= d)
#define REP(n) for (int i = 0; i < n; ++i)

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef INT_MIN
#define INT_MIN -2147483648
#endif
#define LL_MIN -9223372036854775808
#define LL_MAX 9223372036854775807

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;
using TI = tuple<int, int, int>;

#define ZEROS_B(x) __builtin_clz(x)
#define ZEROS_E(x) __builtin_ctz(x)

constexpr double pi = acos(-1);
constexpr int mod = 998244353;
constexpr double eps = 1e-10;
constexpr int N = 1e2 + 10;

template <typename T> T gcd(T a, T b) {
  if (!a || !b) return a | b;
  unsigned shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if (a > b) swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}

template <typename T> T LCM(T a, T b) { return a / GCD(a, b) * b; }

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
    int m = n / 3;
    int tl[m];
    int tr[m];
    int mm[m];
    int found = 0;
    bool ans = true;
    int tc = 0, mc = 0;
    LPI(i, 0, n, 1) {
      if (s[i] == 'T')
        ++tc;
      else
        ++mc;
    }
    if (tc != 2 * mc) {
      cout << "NO\n";
      continue;
    }
    LPI(i, 0, n, 1) {
      if (s[i] == 'T') {
        tl[found] = i;
        ++found;
        if (found == m) break;
      }
    }
    found = 0;
    LPI(i, 0, n, 1) {
      if (s[i] == 'M') {
        mm[found] = i;
        if (mm[found] < tl[found]) {
          ans = false;
          break;
        }
        ++found;
        if (found == m) break;
      }
    }
    found = 0;
    LPI(i, tl[m - 1] + 1, n, 1) {
      if (s[i] == 'T') {
        tr[found] = i;
        if (tr[found] < mm[found]) {
          ans = false;
          break;
        }
        ++found;
        if (found == m) break;
      }
    }
    ans ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}
