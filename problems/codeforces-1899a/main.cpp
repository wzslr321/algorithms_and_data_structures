#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
  int n;
  cin >> n;

  cout << (((n - 1) % 3 != 0 && (n + 1) % 3 != 0) ? "Second" : "First") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
