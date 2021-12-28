#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

const int N = 2 * 10e5 + 1;
vector<pair<int, int>> tree(N);
vector<int> parent(N);
string c;
int n, k;
int dp = 0;
vector<bool> dped(N);

string ans = "";
auto is_worth(int node) -> bool {
  // if(c[node] == 
  if ((node == 1 || dped[parent[node]]) && dp < k && dped[node] != true) {
    LPI(i, node, n, 1) {
      if (c[i] < c[node - 1]) return false;
    }
    return true;
  }
  return false;
}
auto scan(int node) -> void {

  if (tree[node].first != 0) {
    scan(tree[node].first);
    bool worth = is_worth(node);
    if (worth) ans += c[node - 1], ++dp, dped[node] = true;
  }

  {
    ans += c[node - 1];
    bool worth = is_worth(node);
    if (worth) ans += c[node - 1], ++dp, dped[node] = true;
  }

  if (tree[node].second != 0) {
    scan(tree[node].second);
    bool worth = is_worth(node);
    if (worth) ans += c[node - 1], ++dp, dped[node] = true;
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k >> c;
  LPI(i, 1, n + 1, 1) {
    int l, r;
    cin >> l >> r;
    tree[i] = make_pair(l, r);
    parent[l] = i, parent[r] = i;
  }
  scan(1);

  cout << ans << '\n';

  return 0;
}
