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

const int N = 2 * 1e5 + 7;

auto find_mex(vector<VI> &occurrences, VI &used, int &start) -> int {
  int i = 0;
  int k = 0;
  while (occurrences[i].size() > 0) {
    int best = N;
    for (auto in : occurrences[i])
      if (!used[in] && in >= start) best = min(best, in);
    if (best == N) break;
    k = max(k, best), ++i;
  }
  !k ? start = N : start = k + 1;

  return i;
}

auto solve() -> void {
  int n;
  vector<VI> occurrences(N);
  VI used(N);
  int start = 0;

  cin >> n;
  LPI(i, 0, n, 1) {
    int num;
    cin >> num;
    occurrences[num].PB(i);
  }

  VI mex;
  while (start < n)
    mex.PB(find_mex(occurrences, used, start));

  cout << mex.size() << '\n';
  for (auto el : mex)
    cout << el << ' ';
  cout << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
