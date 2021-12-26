#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < b; i += d)

using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
using PI = pair<int, int>;

unordered_map<int, pair<int, vector<int>>> edges;
int n, k;

const int N = 2 * 10e5 + 1;
bool exists[N];

void dfs(int root) {
  int depth = 0;
  queue<int> qq;
  qq.push(root);
  while (qq.size() > 0) {
    auto curr = qq.front();
    cout << "current: " << curr << " depth: " << edges[curr].first << '\n';
    qq.pop();
    for (auto ch : edges[curr].second) {
      qq.push(ch);
    }
  }
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  int root;
  LPI(i, 1, n, 1) {
    int u, v;
    cin >> u >> v;
    if (exists[u] == true) {
      edges[u].second.PB(v);
      edges[v].first = edges[u].first + 1;
      exists[v] = true;
      continue;
    }
    if (exists[v] == true) {
      edges[v].second.PB(u);
      edges[u].first = edges[v].first + 1;
      exists[u] = true;
      continue;
    }
    root = u;
    edges[u].first = 0;
    edges[u].second.PB(v);
    exists[u] = true, exists[v] = true;
  }

  dfs(root);

  return 0;
}
