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
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = false;
    if (b + c == a) ans = true;
    if (a + c == b) ans = true;
    if (a + b == c) ans = true;
    if (a == b && c % 2 == 0) ans = true;
    if (c == b && a % 2 == 0) ans = true;
    if (c == a && b % 2 == 0) ans = true;

    ans ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}
