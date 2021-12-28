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
char best;
bool rdp = false;

string ans = "";
auto is_worth(int node) -> bool {
  if (node == 1 && rdp && dp < k) {
    return true;
  }
  if ((node == 1 || dped[parent[node]]) && dp < k && dped[node] != true) {
    LPI(i, node, n, 1) {
      if (c[i] < c[node - 1]) return false;
    }
    if (node == n) return false;
    return true;
  }
  return false;
}

auto scan(int node) -> void {
  if (tree[node].first != 0) {
    scan(tree[node].first);
    if (is_worth(node)) ans += c[node - 1], ++dp, dped[node] = true;
  }

  ans += c[node - 1];
  if (is_worth(node)) ans += c[node - 1], ++dp, dped[node] = true;

  if (tree[node].second != 0) {
    scan(tree[node].second);
    if (is_worth(node)) ans += c[node - 1], ++dp, dped[node] = true;
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k >> c;
  best = 'z';
  for (auto el : c) {
    if (el < best) best = el;
  }
  LPI(i, 1, n + 1, 1) {
    int l, r;
    cin >> l >> r;
    tree[i] = make_pair(l, r);
    parent[l] = i, parent[r] = i;
  }
  if (c[tree[1].first - 1] == best) rdp = true;
  if (rdp) dped[1] = true;
  scan(1);

  cout << ans << '\n';

  return 0;
}
