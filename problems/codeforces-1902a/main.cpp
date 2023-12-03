#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (n == 1) {
    cout << (s[0] == '0' ? "YES\n" : "NO\n");
    return;
  }
  bool can = false;
  int zeros = 0;
  int ones = 0;
  for (int i = 0; i < n - 1; i++) {
    zeros += s[i] == '0';
    ones += s[i] == '1'; 
    if (s[i] != s[i + 1]) can = true; 
  }
  zeros += s[n - 1] == '0';
  ones += s[n - 1] == '1';

  if (!can) can = zeros > ones;
  cout << (can ? "YES\n" : "NO\n");
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
