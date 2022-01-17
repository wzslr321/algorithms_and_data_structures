#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

int n;
auto solve() -> void {
  cin >> n;
  vector<PI> arr(n);
  LPI(i, 0, n, 1) {
    int tmp;
    cin >> tmp;
    arr[i] = {i, tmp};
  }
  sort(arr.begin(), arr.end(), [](PI a, PI b) { return a.second < b.second; });
  int ans = INT_MIN;
  LPI(i, 0, n, 1) {
    int j = n - 1;
    while (i < j) {
      if (arr[i].first < arr[j].first) {
        ans = arr[j].second - arr[i].second;
        goto finish; // 😎 The borbidden fruit taster the best 😎
      }
      --j;
    }
  }
finish:
  cout << max(ans, 0) << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
