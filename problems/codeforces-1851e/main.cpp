#pragma GCC optimize("03")
#pragma GCC target("tune=native")

#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;
typedef long double ld;

using namespace std;

int n, k;
vector<int> costs;
vector<ll> dp;
vector<vector<int>> graph;

ll scan(int i) {
  if (dp[i] >= 0) return dp[i];
  ll cost = costs[i];
  ll curr = 0;
  for (int j = 0; j < graph[i].size(); j++) {
    ll s = scan(graph[i][j] - 1);
    curr += s;
    dp[graph[i][j] - 1] = s;
  }
  ll best = min(cost, curr);
  dp[i] = best;
  return best;
}

void solve() {
  cin >> n >> k;
  dp.assign(n, -1);
  costs.assign(n, -1);
  graph.assign(n, vector<int>());
  rep(i, 0, n) cin >> costs[i];
  rep(i, 0, k) {
    int index;
    cin >> index;
    dp[index - 1] = 0;
  }
  rep(i, 0, n) {
    int m;
    cin >> m;
    graph[i].resize(m);
    if (!m && dp[i]) dp[i] = costs[i];
    rep(j, 0, m) cin >> graph[i][j];
  }
  rep(i, 0, n) cout << scan(i) << ' ';
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int _ = 1;
  cin >> _;
  while (_--)
    solve();
}
