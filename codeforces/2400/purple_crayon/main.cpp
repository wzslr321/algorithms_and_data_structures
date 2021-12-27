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
bool visited_p[N];
int infected[N];

unordered_map<int, pair<int, vector<int>>> edges;
unordered_map<int, int> parent;
unordered_map<int, vector<int>> deepest;

void find_parents() {
  queue<int> qq;
  qq.push(1);
  while (qq.size() > 0) {
    auto curr = qq.front();
    visited_p[curr] = true;
    qq.pop();
    for (auto ch : edges[curr].second) {
      if (visited_p[ch]) {
        parent[curr] = ch;
        continue;
      }
      qq.push(ch);
    }
  }
}

// update depth of nodes, so it is easy to start coloring from leaves
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
      if (visited_dfs[ch]) continue;
      qq.push(ch);
    }
  }
}

// check if current node is worth painting
bool should_paint(int node) {
  stack<int> st;
  st.push(node);
  while (st.size() > 0) {
    auto curr = st.top();
    if (infected[curr]) return false;
    st.pop();
    for (auto ch : edges[curr].second) {
      // similar functtionality to visited;
      if (parent[curr] == ch) continue;
      st.push(ch);
    }
  }
  // no infected nodes found in this subtree, should be painted
  return true;
}

// maybe colored leaves are not optimal to color, though should paint returnet true?
// this greedness should work, but what if subtree that should be painted is 
// not the largest not infected subtree, and there won't be enough crayons to color that bigger
// subtrees later? 
void color_red() {
  int i = 0;
  while (max_deep >= 0) {
    for (size_t j = 0; j < deepest[max_deep].size(); ++j) {
      // answer is already maximized, don't color more
      if (i == k || i == n / 2) return;
      // tree is already infected, check next node;
      if (!should_paint(deepest[max_deep][j])) continue;

      int current = parent[deepest[max_deep][j]];
      while (current != 1) {
        if (infected[current] == true) break;
        infected[current] = true;
        current = parent[current];
      }
      ++r, ++i;
      infected[deepest[max_deep][j]] = true;
    }
    --max_deep;
  }
  // if shouldn't paint occurred too many times, and
  // colored are less than K, set r to maximize the value 🤕
  // how though?
  // r * (n - r) <-- it have to be maximized
  // it will be maximized if abs((n/2) -  r) is as closest to n/2
  if (i < k) {
    // should paint occured so many times, that whole tree is infected,
    // it doesn't matter which nodes we will color now, since there can't be
    // blue nodes we just maximize r --> set it closest to n/2 if k > n/2 or k
    // if less,
    if (k < n / 2)
      r = k;
    else
      r = n / 2;
  }
}

void color_blue() {
  queue<int> qq;
  qq.push(1);
  while (qq.size() > 0) {
    auto curr = qq.front();
    visited_c[curr] = true;
    // already maximized
    if (blue == n / 2) break;
    // subtree not infected, color to blue
    if (!infected[curr]) ++blue;
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
  infected[1] = true;

  find_parents();
  dfs();
  color_red();
  color_blue();

  cout << ((n - r - blue) * (r - blue)) << '\n';

  return 0;
}
