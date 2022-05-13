#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

auto solve(string s) -> int {
  auto ans = 0;
  auto sz = s.size();

  int left[sz], right[sz];
  {
    unordered_map<char, int> seen_l, seen_r;
    auto occ_l = 0, occ_r = 0;
    for (size_t i = 0, j = sz - 1; i < sz; ++i, --j) {
      if (!seen_l[s[i]]) ++occ_l, seen_l[s[i]] = true;
      if (!seen_r[s[j]]) ++occ_r, seen_r[s[j]] = true;
      left[i] = occ_l, right[j] = occ_r;
    }
  }

  for (size_t i = 0; i < sz - 1; ++i) {
    if (left[i] == right[i + 1]) ++ans;
  }

  return ans;
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cout << solve("aacaba") << '\n';

  return 0;
}
