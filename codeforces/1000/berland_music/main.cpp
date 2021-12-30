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

const int N = 2 * 10e5 + 1;
int arr[N];
int vals[N];
int ans[N];

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    LPI(i, 0, n, 1) {
      cin >> arr[i];
      vals[arr[i] - 1] = i;
    }
    string s;
    cin >> s;
    int curr = 1;
    LPI(c, '0', '2', 1) {
      LPI(i, 0, n, 1) {
        if (s[vals[i]] == c) ans[vals[i]] = curr++;
      }
    }
    LPI(i, 0, n, 1)
    cout << ans[i] << ' ';
    cout << '\n';
  }

  return 0;
}
