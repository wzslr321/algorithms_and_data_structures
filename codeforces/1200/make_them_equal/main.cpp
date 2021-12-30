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

int n;
char c;
int cn;

bool find_prime() {
  int i = 2;
  while (i < cn) {
    if (cn % i == 0) return false;
    ++i;
  }
  return true;
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> c;
    cn = n;
    string s;
    cin >> s;
    while (!find_prime())
      --cn;

    bool ans = false;
    bool alev = true;
    LPI(i, 0, n, 1) {
      if (s[i] != c && i != cn) {
        ans = true;
        if (i % 2 != 0) alev = false;
      }
    }
    if (!ans) {
      cout << "0\n";
      continue;
    }
    if (s[cn] != c) {
      if (alev) {
        cout << "1\n2\n";
        continue;
      }
      cout << "2\n";
      cout << "2 " << cn << '\n';
    } else {
      cout << "1\n";
      cout << cn << '\n';
    }
  }

  return 0;
}
