#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

bool can(int64_t n, int64_t k, int64_t v) {
  int64_t sum = 0;
  while (v > 0) {
    sum += v;
    v /= k;
  }
  return sum >= n;
}

void solve() {
  int64_t n, k;
  cin >> n >> k;

  int64_t l = 0, r = n * k;
  while (r > l + 1) {
    int64_t mid = (l + r) / 2;
    if (can(n, k, mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << l + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
