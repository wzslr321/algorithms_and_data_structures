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
    int minc = INT_MAX;
    LPI(i, 0, n, 1) {
      cin >> arr[i];
      minc = min(arr[i], minc);
    }
    int arrb[n];
    int minb = INT_MAX;
    LPI(i, 0, n, 1) {
      cin >> arrb[i];
      minb = min(arrb[i], minb);
    }
    ll ans = 0LL;
    LPI(i, 0, n, 1) {
      if (arr[i] > minc && arrb[i] > minb) {
        int da = arr[i] - minc;
        int db = arrb[i] - minb;
        ans += min(da, db);
        ans += max(da, db) - min(da, db);
      } else {
        if (arr[i] > minc) {
          ans += arr[i] - minc;
        } else {
          ans += arrb[i] - minb;
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
