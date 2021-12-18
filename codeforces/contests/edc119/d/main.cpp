#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;

int coins[3]{1, 2, 3};
const int N = 1000000;
bool ready[N];
int value[N];
bool used[3];

int solve(int bag) {
  if (bag < 0) return 1e9 + 7;
  if (bag == 0) return 0;
  if (ready[bag]) return value[bag];
  int best = 1e9 + 7;
  int i = 0;
  for (auto c : coins) {
    int curr = solve(bag - c) + 1;
    best = min(best, curr);
    if (best == curr) used[i] = true;
    ++i;
  }
  ready[bag] = true;
  value[bag] = best;

  return best;
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    LPI(i, 0, N, 1) { ready[i] = false; }
    int n;
    cin >> n;
    int arr[n];
    int ans = INT_MIN;
    LPI(i, 0, n, 1) { cin >> arr[i]; }
    bool ever_needed = false;
    int mxarr;
    bool n1 = false;
    LPI(i, 0, n, 1) {
      bool need_all = true;
      LPI(j, 0, 3, 1) { used[j] = false; }
      int curr = solve(arr[i]);
      ans = max(ans, curr);
      if (curr == ans) mxarr = arr[i];
      LPI(j, 0, 3, 1) {
        if (used[j] != true) need_all = false;
      }
      if (need_all) ever_needed = true;
      if (n == 1) {
        n1 = true;
        cout << ans << '\n';
      }
      if(need_all && ever_needed && curr == ans) ++ans;
    }

    cout << ans << '\n';
  }

  return 0;
}
