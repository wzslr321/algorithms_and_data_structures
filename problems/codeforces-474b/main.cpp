#include <iostream>
#include <optional>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int n, m;

void solve() {
  cin >> n;
  vector<int> a(n);
  cin >> a[0];
  vector<int> bps{a[0] + 1};
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    bps.push_back(bps[bps.size() - 1] + a[i]);
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    int q;
    cin >> q;
    int l = 0, r = n - 1;
    while (r > l) {
      auto mid = l + (r - l) / 2;
      if (bps[mid] > q) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    cout << l + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
