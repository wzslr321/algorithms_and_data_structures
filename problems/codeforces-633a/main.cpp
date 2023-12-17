#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

int a, b, c;

int gcde(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int x1, y1;
  int g = gcde(b, a % b, x1, y1);
  x = y1, y = x1 - y1 * (a / b);
  return g;
}

void solve() {
  cin >> a >> b >> c;

  int x1, x2;
  int g = gcde(a, b, x1, x2);
  if (c % g || x1 < 0 || x2 < 0) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
