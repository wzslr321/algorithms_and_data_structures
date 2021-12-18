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

const int N = 1000000;
bool ready[N];
bool ready1[N];
bool ready2[N];
int value[N];
int value2[N];
int value3[N];

int solve(int bag, int (&coins)[3], bool (&ready)[N], int (&value)[N]) {
  if (bag < 0) return 1e9 + 7;
  if (bag == 0) return 0;
  if (ready[bag]) return value[bag];
  int best = 1e9 + 7;
  for (auto c : coins) {
    best = min(best, solve(bag - c, coins, ready, value) + 1);
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
    int n;
    cin >> n;
    vector<int> arr(n);
    LPI(i, 0, n, 1) { cin >> arr[i]; }
    int ans = INT_MIN;
    int coins[3]{3, 2, 1};
    bool c3 = true;
    bool c2 = true;
    sort(arr.begin(), arr.end());

    LPI(i, 0, n, 1) {
      int curr = solve(arr[i], coins, ready, value);
      if (arr[i] % 2 != 0) c2 = false;
      if (arr[i] % 3 != 0) c3 = false;
      ans = max(ans, curr);
      if (arr[i] % 2 == 0 && !c2 && ans == curr) {
        int ans2 = INT_MIN;
        LPI(j, 0, n, 1) {
          int coins2[3]{2, 1, 1};
          ans2 = max(ans2, solve(arr[j], coins2, ready1, value2));
        }
        if (ans2 != ans) {
          ++ans;
        }
        int ans3 = INT_MIN;
        LPI(i, 0, N, 1) {
          ready[i] = false;
          value2[i] = INT_MIN;
        }
        LPI(j, 0, n, 1) {
          int coins3[3]{2, 2, 2};
          ans3 = max(ans3, solve(arr[j], coins3, ready1, value2));
        }
        if (ans3 != ans) {
          --ans;
        }
      };

      if (arr[i] % 3 == 0 && !c3 && ans == curr) {
        int ans2 = INT_MIN;
        LPI(j, 0, n, 1) {
          int coins2[3]{3, 3, 3};
          int cur = solve(arr[j], coins2, ready2, value3);
          ans2 = max(ans2, cur);
        }
        if (ans2 != ans) {
          ++ans;
        }
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
