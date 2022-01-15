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

int gcd(int a, int b) {
  if (!a || !b) return a | b;
  auto shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if (a > b) swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}

bool is_prime(int x) {
  int i = 2;
  while (i < sqrt(x) + 1) {
    if (x % i == 0) return false;
    ++i;
  }
  return true;
}

auto solve() -> void {
  int n;
  cin >> n;
  vector<int> arr(n);
  vector<bool> present(n + 1);
  vector<bool> used(n + 1);
  int ans = 0;
  LPI(i, 0, n, 1) {
    cin >> arr[i];
    present[arr[i]] = true;
    if (is_prime(arr[i])) {
      used[arr[i]] = true;
      if (present[1] != true) {
        present[1] = true;
        ++ans;
      }
    }
  }
  LPI(i, 0, n + ans, 1) {
    LPI(j, 0, n, 1) {
      if (arr[i] == arr[j] || used[arr[i]] == true || used[arr[j]] == true)
        continue;
      int gc = gcd(arr[i], arr[j]);
      if (present[gc] != true) {
        ++ans;
        arr.PB(gc);
        present[gc] = true;
      }
    }
  }

  cout << ans << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();

  return 0;
}
