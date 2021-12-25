#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int l = ceil(n / 2);
  ll sum = 0LL;
  VI nums(n);
  LPI(i, 0, n, 1) { cin >> nums[i]; }
  sort(nums.begin(), nums.end());
  if (nums[n - 1] >= nums[n - 2] + nums[n - 3]) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    cout << nums[n - 2] << ' ' << nums[n - 1] << ' ';
    for (int i = n - 3; i >= 0; --i) {
      cout << nums[i] << ' ';
    }
  }

  return 0;
}
