#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> vec(n);
  cin >> vec[0];
  int min_and = vec[0];
  for (int i = 1; i < n; i++) {
    cin >> vec[i];
    min_and &= vec[i];
  }
  if (min_and > 0) {
    cout << 1 << '\n';
    return;
  }

  int ans = 1;
  int curr_and = vec[0];
  for (int i = 0; i < n; i++) {
    curr_and &= vec[i];
    if (curr_and == min_and) {
      if (i == n - 1) break;
      ++ans, curr_and = vec[i + 1];
    }
  }
  if (curr_and != 0) --ans;
  cout << max(ans, 1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
