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

auto solve() -> void {
  ll a, b, c;
  cin >> a >> b >> c;
  auto bn = (a + c) / 2;
  if (bn % b == 0 && b - a == c - b) {
    cout << "YES\n";
    return;
  }
  auto an = 2 * b - c;
  if (an % a == 0 && b - an == c - b) {
    cout << "YES\n";
    return;
  }
  auto cn = 2 * b - a;
  if (cn % c == 0 && b - a == cn - b) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
