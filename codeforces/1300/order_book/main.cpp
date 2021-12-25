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

const int N = 1000;

int stocks[N];
unordered_map<char, map<int, int, greater<int>>> mp;

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, s;
  cin >> n >> s;

  LPI(i, 0, n, 1) {
    char d;
    cin >> d;
    int p, q;
    cin >> p >> q;

    mp[d][p] += q;
  }

  int i = 0;
  auto sz = mp['S'].size();
  auto needed = sz - s;
  if(s > sz) needed = sz;
  int j = 0;
  for (auto const &[key, value] : mp['S']) {
    if (j < needed && needed != sz) {
      ++j;
      continue;
    }
    if (i == s) break;
    cout << "S " << key << ' ' << value << '\n';
    ++i;
  }
  i = 0;
  for (auto const &[key, value] : mp['B']) {
    if (i == s) break;
    cout << "B " << key << ' ' << value << '\n';
    ++i;
  }

  return 0;
}
