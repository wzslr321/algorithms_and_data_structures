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

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int b1 = n / 3;
    int b2 = b1;
    if(n % 3 == 2) ++b2;
    if(n % 3 == 1) ++b1;
    cout << b1 << ' ' << b2 << '\n';
  }

  return 0;
}
