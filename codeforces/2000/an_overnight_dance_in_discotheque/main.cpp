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
using TI = tuple<int, int, int>;

#define PI 3.14159265358979323846

auto solve() -> void {
  int n;
  cin >> n;
  vector<double> vec(n);
  LPI(i, 0, n, 1) {
    double x, y, r;
    cin >> x >> y >> r;
    vec[i] = PI * (r * r);
  }
  sort(vec.begin(), vec.end(), greater<int>());
  for (auto el : vec) {
    cout << el << '\n';
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
