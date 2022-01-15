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

bool is_valid(ll a, ll b, ll c) {
  if (c - b == b - a) return true;
  return false;
}

auto solve() -> void {
  ll a, b, c;
  cin >> a >> b >> c;
  if (a == b && b == c) {
    cout << "YES\n";
    return;
  }
  if (b - a == c - b) {
    cout << "YES\n";
    return;
  }

  auto needed = (a + c) / 2;
  if (needed - a == c - needed && needed % b == 0 && needed > 0) {
    cout << "YES\n";
    return;
  }

  auto an = abs(c - b) + b;
  if (b - an == c - b && an % a == 0 && an > 0) {
    cout << "YES\n";
    return;
  }
  an = b - abs(c - b);
  if (b - an == c - b && an % a == 0 && an > 0) {
    cout << "YES\n";
    return;
  }

  auto cn = abs(b - a) + b;
  if (b - a == cn - b && cn % c == 0 && cn > 0) {
    cout << "YES\n";
    return;
  }
  cn = b - abs(b - a);
  if (b - a == cn - b && cn % c == 0 && cn > 0) {
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
