#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int n;
constexpr int N = 2 * 10e6;
int org[N];

bool can(int v, vector<int> arr) {
  for (int i = n - 1; i >= 2; i--) {
    if (arr[i] < v)
      return false;
    int d = min(org[i], arr[i] - v) / 3;
    arr[i - 1] += d;
    arr[i - 2] += d * 2;
  }
  return arr[0] >= v && arr[1] >= v;
}

void solve() {
  cin >> n;
  int l = 0, r = 0;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    org[i] = arr[i];
    r = max(arr[i], r);
  }
  while (r > l + 1) {
    int v = (l + r) / 2;

    can(v, arr) ? l = v : r = v;
  }
  cout << (can(l + 1, arr) ? l + 1 : l) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
