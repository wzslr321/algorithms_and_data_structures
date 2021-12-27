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

ll red = 0LL;
ll blue = 0LL;

bool visited_dfs[N];
bool visited_c[N];
bool visited_p[N];
int infected[N];
ll infected_count = 1LL;

unordered_map<int, pair<int, vector<int>>> edges;
unordered_map<int, int> parent;
unordered_map<int, vector<int>> deepest;
vector<int> tc;

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

// maybe colored leaves are not optimal to color, though should paint returnet
// true? this greedness should work, but what if subtree that should be painted
// is not the largest not infected subtree, and there won't be enough crayons to
// color that bigger subtrees later?
void color_red() {
  int i = 0;
  while (max_deep >= 0) {
    int sz = deepest[max_deep].size();
    int j = 0;
    bool l = true;
    while (j < sz) {
      int in = l ? j : sz - j - 1;
      if (i == k || infected_count == n) return;
      // tree is already infected, check next node
      if (infected[deepest[max_deep][in]]) {
        ++j;
        continue;
      }

      int current = parent[deepest[max_deep][in]];
      while (current != 1) {
        if (infected[current] == true) break;
        ++infected_count;
        infected[current] = true;
        current = parent[current];
      }
      ++red, ++i;
      ++infected_count;
      infected[deepest[max_deep][in]] = true;
      l ? l = false : l = true;
      ++j;
    }
    --max_deep;
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

  blue = n - infected_count;
  if (infected_count == n) {
    if (red != infected_count - 1) {
      if (red < k) {
        if (k > n / 2)
          red = n / 2;
        else
          red = k;
      }
    }
  }
  cout << ((n - red - blue) * (red - blue)) << '\n';

  return 0;
}
