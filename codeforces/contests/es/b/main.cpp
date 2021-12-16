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

int is_prime(int n) {
  for (int j = 2; j < n / 2; j++) {
    if ((n % j) == 0) return false;
  }
  return true;
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
    int i = 2;
    for (int j = n - 1 - i; j > 2; j--) {
      if (is_prime(i) && is_prime(j)) {
        cout << i << ' ' << j << " 1" << '\n';
        break;
      }
      ++i;
    }
  }

  return 0;
}
