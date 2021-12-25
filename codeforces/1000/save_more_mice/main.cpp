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

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    auto n{0}, k{0}, cnt{0};
    cin >> n >> k;
    multiset<int, greater<int>> ms{};
    LPI(j, 0, k, 1) {
      auto tmp{0};
      cin >> tmp;
      ms.insert(tmp);
    }

    auto it{ms.begin()};
    auto mv{0};
    while (mv < n) {
      auto el{*it};
      while (el < n) {
        ++el;
        ++mv;
      }
      if (el == n) {
        ++cnt;
        ++it;
      }
    }

    cout << --cnt << '\n';
  }

  return 0;
}
