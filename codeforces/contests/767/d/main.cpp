#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll int64_t

#define PB push_back

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)
#define CZYT(n, arr)                                                           \
  for (int i = 0; i < n; ++i)                                                  \
  cin >> arr[i]

using VI = vector<int>;
using PI = pair<int, int>;

auto solve() -> void {
  int n;
  cin >> n;
  // vector<string> arr(n);
  unordered_map<string, int> needed;
  int pals = 0;
  int cnt = 0;
  LPI(i, 0, n, 1) {
    string str;
    cin >> str;
    vector<string> psb;
    psb.PB(str);
    if (str.size() == 3) {
      string st = "";
      st += str[1];
      st += str[2];
      psb.PB(st);
    }
    string s = "";
    for (int j = str.size() - 1; j >= 0; --j)
      s += str[j];
    for (auto el : psb) {
      bool git = false;
      if (needed[el] == 1) git = true;
      if (git) ++cnt;
    }
    if (s == str) ++pals;
    if (s.size() == 2) {
      string st = "";
      st += s[0];
      st += s[1];
      needed[st] = 1;
    }
    if (s.size() == 3) {
      string st = "";
      st += s[0];
      st += s[1];
      st += s[2];
      needed[st] = 1;
      string st2 = "";
      st2 += s[1];
      st2 += s[2];
      needed[st2] = 1;
    }
  }
  if (cnt >= 1 || pals > 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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