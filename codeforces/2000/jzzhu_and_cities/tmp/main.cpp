#pragma GCC optimize("0fast,unroll-loops")
#pragma GCC target(                                                            \
    "avx2,popcnt,lzcnt,tune=native") // gotta also learn about ctz,blsi and pdep
                                     // and consider abm,bmi,bmi2 targets

#include <bits/stdc++.h>

using namespace std;

#define ZEROS_B(x) __builtin_clz(x)
#define ZEROS_E(x) __builtin_ctz(x)

#define ll long long
#define ld long double

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i{a}; i < b; i += d)
#define LPD(i, a, b, d) for (int i{a}; i < b; i -= d)

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

auto main() -> int {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cout << "100000 149997 1\n";
  int w = 1000000000;
  int i = 1;
  while (i < 149996) {
    cout << i << ' ' << i + 1 << ' ' << w << '\n';
    cout << i << ' ' << i + 2 << ' ' << 1 << '\n';
    i += 2;
  }
  cout << "2 30492883\n";

  return 0;
}
