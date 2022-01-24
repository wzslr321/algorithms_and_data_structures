#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

#define PB push_back

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

auto solve() -> void {
  int n;
  cin >> n;
  VS arr(n);
  multiset<string> suffixes, prefixes;

  bool pal = false;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    auto pali = arr[i];
    reverse(pali.begin(), pali.end());
    if (pali == arr[i]) pal = true;
    suffixes.insert(arr[i]);
  }

  if (pal) {
    cout << "YES\n";
    return;
  }

  for (int i = 0; i < n; ++i) {
    suffixes.erase(suffixes.find(arr[i]));

    auto needed = arr[i];
    reverse(needed.begin(), needed.end());
    if (suffixes.count(needed)) {
      cout << "YES\n";
      return;
    }
    if (arr[i].size() == 3) {
      needed = arr[i].substr(1, 2);
      reverse(needed.begin(), needed.end());
      if (prefixes.count(needed)) {
        cout << "YES\n";
        return;
      }

      needed = arr[i].substr(0, 2);
      reverse(needed.begin(), needed.end());
      if (suffixes.count(needed)) {
        cout << "YES\n";
        return;
      }
    }

    prefixes.insert(arr[i]);
  }

  cout << "NO\n";
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
