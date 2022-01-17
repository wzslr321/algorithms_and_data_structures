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

const int N = 105;
int n;
int monsters[N];
int health[N];

auto solve() -> void {
  int ans = 0;
  unordered_map<int, int> mtr;
  cin >> n;
  LPI(i, 0, n, 1) cin >> monsters[i];
  LPI(i, 0, n, 1) cin >> health[i];
  LPI(i, 0, n, 1) {
    int sum = 1;
    int curr = 1;
    int in = 1;
    int j = monsters[i] - 1;
    while (curr < health[i]) {
      ++in;
      --j, ++curr;
      sum += curr;
    }
    j = monsters[i] - 1;
    int do_wymiany = 0;
    bool zawrotka = false;
    int y;
    LPI(i, 0, in, 1) {
      if (mtr[j - i] && mtr[j - i] > curr) {
        zawrotka = true;
        y = i;
        break;
      }
      ++do_wymiany;
      mtr[j - i] = curr;
      --curr;
    }
    if (zawrotka) {
      LPI(i, 1, do_wymiany + 1, 1) { mtr[j - y + i] = mtr[j - y + i - 1] + 1; }
    }
  }
  for (const auto [key, value] : mtr)
    ans += value;
  cout << ans << '\n';
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
