#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> visited;
int ans = 0;

int dfs(int v) {
  visited[v] = 1;
  int subtree_count = 1;
  for (auto u : graph[v]) {
    if (!visited[u]) subtree_count += dfs(u);
  }
  if(v != 0 && subtree_count % 2 == 0) ++ans;
  return subtree_count;
}

void solve() {
  cin >> n;
  graph.assign(n, vector<int>());
  visited.assign(n, 0);
  rep(i, 0, n - 1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  if(n & 1) cout << -1 << '\n';
  else {
      dfs(0);
      cout << ans << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
}
