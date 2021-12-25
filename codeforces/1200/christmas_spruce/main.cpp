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

  int n;
  cin >> n;
  vector<int> parent(n), children(n);
  LPI(i, 1, n, 1) {
    cin >> parent[i];
    parent[i]--;
    children[parent[i]]++;
  }
  vector<int> leaves(n);
  LPI(i, 0, n, 1) {
    if (children[i] == 0) leaves[parent[i]]++;
  }
  LPI(i, 0, n, 1) {
    if (children[i] > 0 && leaves[i] < 3) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}
