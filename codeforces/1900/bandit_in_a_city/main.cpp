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

const int N = 2 * 1e5 + 7;
vector<int> roads(N);
vector<int> citizens(N);
int n;

auto solve() -> void {
  cin >> n;
  LPI(i, 2, n + 1, 1) {
    int in;
    cin >> in;
    roads[in] = i;
  }
  LPI(i, 1, n + 1, 1) { cin >> citizens[i]; }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
