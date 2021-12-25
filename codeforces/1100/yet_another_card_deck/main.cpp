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

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  VI v;
  LPI(i, 0, n, 1) {
    int num;
    cin >> num;
    v.PB(num);
  }

  LPI(i, 0, q, 1) {
    int qr;
    cin >> qr;
    int pos = find(v.begin(), v.end(), qr) - v.begin();
    cout << pos + 1 << '\n';
    rotate(v.begin(), v.begin() + pos, v.begin() + pos + 1);
  }

  return 0;
}
