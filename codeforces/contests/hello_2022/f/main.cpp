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

std::vector<int> z;
std::vector<int> o;
std::vector<int> d;

size_t iz = 0, io = 0, id = 0;
int curri = -1;

int n, a, b, c;

ll ans = 0ll;

auto licz() -> int {
  if (z.size() > 0 && iz < z.size() && curri != 1) {
    curri = 1;
    ++iz;
    cout << "WITAM a " << a << '\n';
    ans += a;
    return a;
  } else {
    if (o.size() > 0 && curri != 2 && io < o.size()) {
      curri = 2;
      ++io;
      cout << "WITAM b " << b << '\n';
      ans += b;
      return b;
    } else {
      if (d.size() > 0 && curri != 3 && id < d.size()) {
        curri = 3;
        ++id;
        cout << "WITAM c " << c << '\n';
        ans -= c;
        return c;
      }
    }
  }

  return -1;
}

auto solve() -> void {
  cin >> n >> a >> b >> c;
  string s;
  cin >> s;
  LPI(i, 0, s.size() - 1, 1) {
    if (s[i] == '1' && s[i + 1] == '1') o.PB(i), ++i;
    if (s[i] == '0' && s[i + 1] == '0') z.PB(i), ++i;
    if (s[i] == '0' && s[i + 1] == '1') d.PB(i);
  }
  while (licz() != -1)
    licz();
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
