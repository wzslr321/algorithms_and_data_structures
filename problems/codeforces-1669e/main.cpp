#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<string> strings(n);
  rep(i, 0, n) cin >> strings[i];
  vector<set<string>> ans(26, set<string>());
  rep(i, 0, n) ans[strings[i][0] - 'a'].insert(strings[i]);
  ll cnt = 0;
  rep(i, 0, n) { 
      cnt += ans[i].size(); 
      for(const auto s : ans[i]) {
          cout << "found: " << s << '\n';
      }
  }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
