#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

void solve() {
  int n, l, t;
  ull p;
  cin >> n >> p >> l >> t;

  int lower = 0, upper = n;
  while (lower < upper) {
    int days = lower + (upper - lower) / 2;
    ull sum = l;
    sum *= days;
    ll tasks = ceil(n / 7.);
    sum += min(days * 2ll, tasks) * t;
    if (sum >= p) {
      upper = days;
    } else {
      lower = days+ 1;
    }
  }

  cout << n - lower << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}

