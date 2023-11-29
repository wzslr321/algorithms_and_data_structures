#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

void solve() {
  int64_t k, x;
  cin >> k >> x;
  int64_t l = 1, r = 2 * k - 1;
  while (l < r) {
    auto mid = l + (r - l) / 2;
    int64_t csum = 0;
    if(mid <= k) {
        csum +=  ((1 + mid) * mid) / 2;
    } else {
        csum +=  ((1 + k) * k) / 2;
        auto n = mid - k;
        csum += ((2 * (k - 1) + (n - 1) * -1) * n) / 2;
    }
    if(csum >= x) {
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
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
