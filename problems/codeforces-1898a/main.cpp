#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

int n, k;
string s;
void solve() {
  cin >> n >> k >> s;
  int bc = 0;
  for (auto c : s)
    if (c == 'B') ++bc;
  if (bc == k) {
    cout << 0 << '\n';
    return;
  }
  int i = 0;
  while (i < n && bc > k) {
    if (s[i] == 'B') --bc;
    ++i;
  }
  if (i) {
    cout << 1 << '\n' << i << " " << 'A' << '\n';
    return;
  }
  i = 0;
  while (i < n && bc < k) {
    if (s[i] == 'A') ++bc;
    ++i;
  }
  cout << 1 << '\n' << i << " " << 'B' << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
