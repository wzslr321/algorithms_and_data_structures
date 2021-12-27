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

bool marked[N];
vector<pair<int, int>> kolorki;
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

void powrzucaj() {
  while (max_deep > 0) {
    for (size_t i = 0; i < deepest[max_deep].size(); ++i) {
      int length = 0;
      int curr = deepest[max_deep][i];
      int current = parent[curr];
      marked[curr] = true;
      while (!marked[current]) {
        marked[current] = true;
        current = parent[current];
        ++length;
      }
      kolorki.PB(make_pair(curr, length));
    }
    --max_deep;
  }
}

void color_red() {
  sort(kolorki.begin(), kolorki.end(),
       [](const std::pair<int, int> &a, const std::pair<int, int> &b) {
         return a.second > b.second;
       });
  int lk = k;
  LPI(i, 0, k, 1) {
    if (infected_count == n || red == lk) break;
    if (infected[kolorki[i].first]) {
      ++k;
      continue;
    }
    infected[kolorki[i].first] = true;
    ++red, ++infected_count;
    int current = parent[kolorki[i].first];
    while (current != 1) {
      if (infected[current]) break;
      infected[current] = true;
      current = parent[current];
      ++infected_count;
    }
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  int lk = k;
  LPI(i, 1, n, 1) {
    int u, v;
    cin >> u >> v;
    edges[u].second.PB(v);
    edges[v].second.PB(u);
  }
  infected[1] = true;
  marked[1] = true;

  find_parents();
  dfs();
  powrzucaj();
  color_red();

  blue = n - infected_count;
  if (infected_count == n) {
    if (red != infected_count - 1) {
      if (red < lk) {
        if (lk > n / 2)
          red = n / 2;
        else
          red = lk;
      }
    }
  }
  blue = max(blue, 0LL);
  blue = min(blue, n / 2);
  cout << ((n - red - blue) * (red - blue)) << '\n';

  return 0;
}
