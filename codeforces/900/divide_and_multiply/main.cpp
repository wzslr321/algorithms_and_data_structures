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
    int psb = 0, mx = 0, sum = 0;
    LPI(i, 0, n, 1) {
      cin >> arr[i];
      while (arr[i] % 2 == 0)
        arr[i] /= 2, ++psb;
      mx = max(mx, arr[i]);
      sum += arr[i];
    }

    cout << sum - mx + ((ll)mx << psb) << '\n';
  }

  return 0;
}
