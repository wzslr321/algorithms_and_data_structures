#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)
#define CZYT(n, arr)                                                           \
  for (int i = 0; i < n; ++i)                                                  \
  cin >> arr[i]

using VI = vector<int>;
using PI = pair<int, int>;

// holds info about its sequence length (how long it have to cast, to kill
// monster) So, when we get to the point, where
// charging spell from previous monster is not enough, we have to extend
// previous sequences from proper monster.

// Sn = ((a1 + an) / 2) * n;
// n = health[i]
// an = monsters[i];
// Sn = ?
// an = a1 + (n - 1) * r;
// a1 = monsters[i] - (n - 1) * r => a1 = monsters[i] - (health[i] - 1) * 1;
// Sn = ((a1 + an) / 2) * n;
// well, that's kidna right, but when we have to keep casting spell to have
// enough damage to kill monster, our a1 and n will change.

auto solve() -> void {
  int n;
  cin >> n;
  int monsters[n];
  int health[n];
  int mana[n];
  // First monster spawns at e.g. 4th sec, so subsequence length will surely
  // also be 4.
  CZYT(n, monsters);
  CZYT(n, health);
  {
    auto a1 = 1, n = health[0], an = health[0];
    auto sn = ((a1 + an) / 2.) * n;
    mana[0] = sn;
  }
  LPI(i, 1, n, 1) {
    int j = i;
    while (monsters[i] - monsters[j - 1] + 1 < health[i])
      --j;

    int a1, nc;
    if (j == i)
      a1 = 1, nc = health[i];
    else
      a1 = health[j], nc = health[i] - health[j];

    auto an = health[i];
    auto sn = ((a1 + an) / 2.) * nc;
    mana[i] = sn;
  }

  int ans = 0;
  LPI(i, 0, n, 1) ans += mana[i];
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
