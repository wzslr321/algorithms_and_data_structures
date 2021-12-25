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
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  multiset<int> mst;

  LPI(i, 0, n, 1) {
    int sc;
    cin >> sc;
    mst.insert(sc);
  }

  auto it = mst.end();
  int i{0};
  while (i < k) {
    --it;
    ++i;
  }

  auto x = count_if(mst.begin(), mst.end(),
                    [it](auto arg) { return arg >= *it && arg > 0; });
  cout << x << '\n';

  return 0;
}
