#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

int gcd(int a, int b) {
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

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a = (n - 1) / 2;
    int b = (n - 1) / 2;
    int c = 1;
    while (gcd(a, b) != 1) {
      --a;
      ++b;
      if (a + b + c < n) ++a;
      if (a + b + c > n) --a;
    }
    cout << a << ' ' << b << ' ' << c << '\n';
  }

  return 0;
}
