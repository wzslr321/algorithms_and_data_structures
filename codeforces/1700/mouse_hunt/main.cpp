#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

int n;
int N = 2 * 1e5 + 7;
int c[N];
int a[N];

vector<pair<int, int>> adj;

auto wczytaj() -> void {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> c[i];
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}

auto solve() -> void { wczytaj(); }

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
