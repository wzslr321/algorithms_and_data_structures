#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

#define PB push_back

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)
#define CZYT(n, arr)                                                           \
  for (int i = 0; i < n; ++i)                                                  \
  cin >> arr[i]

using VI = vector<int>;
using PI = pair<int, int>;

int M, N, K;
const int MAX_K = 100007;
vector<PI> bricks(MAX_K);

auto solve() -> void {
  cin >> M >> N >> K;
  LPI(i, 0, K, 1) {
    int x, y;
    cin >> x >> y;

  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
