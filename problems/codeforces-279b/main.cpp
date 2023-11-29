#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int n, t;

void solve() {
  cin >> n >> t;
  vector<int> a(n);
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  vector<int> sums(n + 1);
  sums[0] = 0;
  for (int i = 0; i < n; ++i)
    sums[i + 1] = sums[i] + a[i];
  int l = 0, r = n;
  while (l < r) {
    int mid = l + (r - l) / 2;
    bool can = false;
    for (int j = 0; j < n - mid; ++j) {
      if (sums[mid + j + 1] - sums[j] <= t) {
        can = true;
        break;
      }
    }
    if (!can) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
