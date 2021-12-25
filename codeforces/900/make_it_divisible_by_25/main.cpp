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

const VS subseqs{"00", "25", "50", "75"};

int solve(string &s, string &t) {
  auto sb{s.length() - 1};

  auto ans{0};
  while (sb >= 0 && s[sb] != t[1]) {
    --sb;
    ++ans;
  }

  if (sb < 0) return INT_MAX;

  --sb;

  while (sb >= 0 && s[sb] != t[0]) {
    --sb;
    ++ans;
  }

  return sb < 0 ? INT_MAX : ans;
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    string n{};
    cin >> n;

    auto ans{INT_MAX};
    for (auto e : subseqs)
      ans = min(ans, solve(n, e));

    cout << ans << '\n';
  }

  return 0;
}
