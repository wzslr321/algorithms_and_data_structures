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
const int N = 1e6 + 7;
int arr[N];
ll sumy[N];
ll ans = 0LL;

auto solve() -> void {
  cin >> n;
  ll suma = 0LL;
  LPI(i, 0, n, 1) {
    cin >> arr[i];
    suma += arr[i];
    sumy[i] = suma;
    if (!(arr[i] & 1)) ++ans;
    if (!(suma & 1)) ++ans;
  }

  cout << ans << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
