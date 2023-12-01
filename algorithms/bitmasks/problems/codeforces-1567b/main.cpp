#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int calculate_xor(int n) {
  if (n % 4 == 0) return n;
  if (n % 4 == 1) return 1;
  if (n % 4 == 2) return n + 1;
  return 0;
}

void solve() {
  int a, b;
  cin >> a >> b;
  int x = calculate_xor(a - 1);
  int ans = a;
  if (x != b && (x ^ b) != a) ++ans;
  if (x != b && (x ^ b) == a) ans += 2;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
