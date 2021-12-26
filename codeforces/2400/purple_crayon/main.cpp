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
unordered_map<int, vector<int>> deepest;
int n, k;

const int N = 2 * 10e5 + 1;
bool exists[N];
int max_deep = INT_MIN;

void dfs(int root) {
  int depth = 0;
  queue<int> qq;
  qq.push(root);
  while (qq.size() > 0) {
    auto curr = qq.front();
    max_deep = max(max_deep, edges[curr].first);
    deepest[edges[curr].first].PB(curr);
    qq.pop();
    for (auto ch : edges[curr].second) {
      qq.push(ch);
    }
  }
}
unordered_map<int, bool> red;

bool scan_children(int node) {
  stack<int> st;
  st.push(node);
  while (st.size() > 0) {
    auto curr = st.top();
    if (red[curr] == true) return false;
    st.pop();
    for (auto ch : edges[curr].second) {
      st.push(ch);
    }
  }
  return true;
}

int r = 0;
void color_red() {
  int i = 0;
  int y = -1;
  while (max_deep > 0) {
    for (size_t j = 0; j < deepest[max_deep].size(); ++j) {
      if (i == k) {
        y = j;
        return;
      }
      ++r;
      red[deepest[max_deep][j]] = true;
      ++i;
    }
    --max_deep;
  }
}

int root;
int blue = 0;
void color_blue() {
  int best = n / 2;
  for (size_t i = 0; i < deepest[max_deep].size(); ++i) {
    int curr = deepest[max_deep][i];
    if (deepest[max_deep][i] == deepest[max_deep].back() && max_deep > 0)
      --max_deep;
    if (scan_children(curr)) ++blue;
    if (blue == best) break;
  }
}

auto main() -> int {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
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
    edges[v].first = 1;
    edges[u].second.PB(v);
    exists[u] = true, exists[v] = true;
  }

  dfs(root);
  color_red();
  color_blue();

  cout << ((n - r - blue) * (r - blue)) << '\n';

  return 0;
}
