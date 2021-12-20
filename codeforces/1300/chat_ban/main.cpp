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
constexpr int N = 1e2 + 10;

template <typename T> T gcd(T a, T b) {
  if (!a || !b)
    return a | b;
  unsigned shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if (a > b)
      swap(a, b);
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
      ll k,x;
      cin >> k >> x;
      ll ans = 0LL;
      ll sum1 = 0LL;
      int i = k;
      while(true) {
         sum1 = ((1LL + i) / 2.) * i;
         ll sum2 = ((1LL + (i + 1) ) / 2.) * (i + 1);
         if(sum1 < x && sum1 + sum2 >= x ) {
             ans = i + 1;
             break;
         }
         if( sum1 >= x) i /= 2;
         else i += i / 2;
      }
      if(sum1 >= x) {
          cout << ans << '\n';
          continue;
      }
      int j = k - 1;
      LPD(i,k - 1,0,1) {
         ll an = k - 1 + (j - 1) * -1LL;
         ll an2 = k - 1 + j * -1LL;
         ll sumd = ((k - 1 + an) / 2.) * j;
         ll sumd2 = ((k - 1 + an2) / 2.) * j + 1;
         if(sum1 + sumd <= x && sum1 + sumd2 >= x) {
             ans += j + 1;
         }
         if( sum1 + sumd >= x) {
            j /= 2;
            break;
         }  else i += i / 2;
      }

      cout << ans << '\n';
  }

  return 0;
}
