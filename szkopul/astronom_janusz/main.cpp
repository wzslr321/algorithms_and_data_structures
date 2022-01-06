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
  int n;
  cin >> n;
  int prev;
  int curr;
  LPI(i, 0, n, 1) {
    prev = curr;
    cin >> curr;
  }
  if (curr == 15) {
    cout << "DOWN\n";
    return;
  }
  if (curr == 0) {
    cout << "UP\n";
    return;
  }
  if (n == 1) {
    cout << "UNKNOWN\n";
    return;
  }
  if (prev > curr)
    cout << "DOWN\n";
  else
    cout << "UP\n";
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
