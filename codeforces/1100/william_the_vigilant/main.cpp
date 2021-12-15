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
#define LPD(i, a, b, d) for (int i = a; i > b; i -= d)
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

const int N = 1e5 + 3;
char s[N];
int ans = 0;
int n, q;

int solve(int p) {
  if (p > n + 2 || p < 1) return 0;

  if (s[p] == 'a' && s[p + 1] == 'b' && s[p + 2] == 'c') return 1;
  return 0;
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> q;
  cin >> s + 1;
  LPI(i, 1, n, 1) { ans += solve(i); }
  LPI(i, 0, q, 1) {
    int pos;
    char c;
    cin >> pos;
    cin >> c;
    ans -= solve(pos - 2) + solve(pos - 1) + solve(pos);
    s[pos] = c;
    ans += solve(pos - 2) + solve(pos - 1) + solve(pos);
    cout << ans << '\n';
  }

  return 0;
}
