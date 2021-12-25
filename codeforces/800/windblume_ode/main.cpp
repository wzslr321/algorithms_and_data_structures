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

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    LPI(i, 0, n, 1) {
      cin >> arr[i];
      sum += arr[i];
    }
    auto bad = is_prime(sum);
    int j = -1;
    if (bad) {
      LPI(i, 0, n, 1) {
        if (arr[i] & 1) {
          j = i;
          break;
        }
      }
    }
    bad ? cout << n - 1 << '\n' : cout << n << '\n';
    LPI(i, 1, n + 1, 1) {
      if (i != j + 1) cout << i << ' ';
    }
    cout << '\n';
  }

  return 0;
}
