#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

auto solve() -> void {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  for (int i = 0; i < n; ++i)
    cin >> b[i];
  for (int i = 0; i < n; ++i) {
    if (a[i] < b[i]) {
      int tmp = a[i];
      a[i] = b[i];
      b[i] = tmp;
    }
  }

  int mna = INT_MIN;
  int mnb = INT_MIN;
  for (int i = 0; i < n; ++i) {
    mna = max(a[i], mna);
    mnb = max(b[i], mnb);
  }

  cout << mna * mnb << '\n';
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
