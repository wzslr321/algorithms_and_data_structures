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

//

ll n, k;
const int N = 2 * 10e5 + 1;
int max_deep = INT_MIN;

ll r = 0LL;
ll blue = 0LL;

bool visited_dfs[N];
bool visited_c[N];
int infected[N];

unordered_map<int, pair<int, vector<int>>> edges;
unordered_map<int, int> parent;
unordered_map<int, vector<int>> deepest;
unordered_map<int, bool> red;

void find_parents() {
  bool vs[N];
  queue<int> qq;
  qq.push(1);
  while (qq.size() > 0) {
    auto curr = qq.front();
    vs[curr] = true;
    qq.pop();
    for (auto ch : edges[curr].second) {
      if (vs[ch]) {
        parent[curr] = ch;
        continue;
      }
      qq.push(ch);
    }
  }
}

void dfs() {
  int depth = 0;
  edges[1].first = depth;
  queue<int> qq;
  qq.push(1);
  while (qq.size() > 0) {
    auto curr = qq.front();
    visited_dfs[curr] = true;
    if (curr != 1) edges[curr].first = edges[parent[curr]].first + 1;
    max_deep = max(max_deep, edges[curr].first);
    deepest[edges[curr].first].PB(curr);
    qq.pop();
    for (auto ch : edges[curr].second) {
      if (visited_dfs[ch]) {
        parent[curr] = ch;
        continue;
      }

      qq.push(ch);
    }
  }
}

bool should_paint(int node) {
  stack<int> st;
  st.push(node);
  while (st.size() > 0) {
    auto curr = st.top();
    if (red[curr] == true) return false;
    st.pop();
    for (auto ch : edges[curr].second) {
      if (parent[curr] == ch) continue;
      st.push(ch);
    }
  }
  return true;
}

void color_red() {
  int i = 0;
  int y = -1;
  while (max_deep >= 0) {
    for (size_t j = 0; j < deepest[max_deep].size(); ++j) {
      if (i == k || i == n / 2) {
        y = j;
        return;
      }
      if (!should_paint(deepest[max_deep][j])) continue;

      int current = parent[deepest[max_deep][j]];
      while (current != 1) {
        infected[current] = true;
        current = parent[current];
      }
      ++r;
      red[deepest[max_deep][j]] = true;
      ++i;
    }
    --max_deep;
  }
  if (i < k) {
    if (k > n / 2)
      r = n / 2;
    else
      r = k;
  }
}

void color_blue() {
  queue<int> qq;
  qq.push(1);
  while (qq.size() > 0) {
    auto curr = qq.front();
    visited_c[curr] = true;
    if (infected[curr] != true && red[curr] != true && curr != 1) {
      ++blue;
    }
    qq.pop();
    for (auto ch : edges[curr].second) {
      if (visited_c[ch]) continue;
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
  LPI(i, 1, n, 1) {
    int u, v;
    cin >> u >> v;
    edges[u].second.PB(v);
    edges[v].second.PB(u);
  }

  find_parents();
  dfs();
  color_red();
  color_blue();

  cout << static_cast<ll>(((n - r - blue) * (r - blue))) << '\n';

  return 0;
}
