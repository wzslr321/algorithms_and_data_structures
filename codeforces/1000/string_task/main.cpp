#include <bits/stdc++.h>

using namespace std;

#define PB push_back

using VI = vector<int>;
using PI = pair<int, int>;

unordered_map<char, bool> vowels{
    {'a', true}, {'o', true}, {'y', true},
    {'e', true}, {'u', true}, {'i', true},
};

auto solve() -> void {
  string s;
  cin >> s;
  vector<char> ans(s.size() << 1);
  int j = 0;
  for (size_t i = 0; i < s.size(); ++i) {
    auto ch = tolower(s[i]);
    if (vowels[ch]) continue;
    ans[j] = '.';
    ans[++j] = ch;
    ++j;
  }

  for(int i = 0; i < j; ++i) {
      cout << ans[i];
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
