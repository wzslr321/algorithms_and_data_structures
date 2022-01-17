#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back

#define LPI(i, a, b, d) for (int(i) = a; (i) < (int)(b); (i) += (d))

using PI = pair<int, int>;
using VVPI = vector<vector<pair<PI, int>>>;
using VI = vector<int>;

// make it possible to store pair as map key
namespace std {
template <typename T, typename U> struct hash<std::pair<T, U>> {
  auto operator()(const std::pair<T, U> &pair) const noexcept {
    auto const hash_t = std::hash<T>{}(pair.first);
    auto const hash_u = std::hash<U>{}(pair.second);
    return hash_t ^ hash_u;
  }
};
} // namespace std

auto solve() -> void {
  int n, m, k; // a, b, c, d, h;
  cin >> n >> m >> k;
  vector<VI> dist(n + 1, VI(m + 1));
  auto graph = unordered_map<PI, vector<pair<PI, int>>>();

  int hx[n + 1];

  LPI(i, 1, n + 1, 1) cin >> hx[i];

  LPI(i, 0, k, 1) {
    cin >> a >> b >> c >> d >> h;
    graph[{a, b}].PB({{c, d}, h});
  }

  dist[1][1] = 0;
  priority_queue<PI> pq;
  pq.push({1, 1});
  while (!pq.empty()) {
    auto curr = pq.top();
    int x = curr.first, y = curr.second;
    pq.pop();

    // Find other leaders on that floor by going on feet
    LPI(i, 1, m + 1, 1) {
      auto current = graph[{x, i}];
      if ((!current.empty() || (x == n && i == m))) {
        if (i != y) {
          graph[curr].PB({{x, i}, abs(y - i) * hx[x]});
        }
      }
    }

    LPI(i, 0, graph[curr].size(), 1) {
      auto curr_el = graph[curr][i].first;
      auto curr_w = graph[curr][i].second;
      int x2 = curr_el.first, y2 = curr_el.second;
      auto c1 = x2 == x && dist[x][y] + curr_w < dist[x2][y2];
      auto c2 = x2 != x && dist[x][y] - curr_w < dist[x2][y2];
      if (!dist[x2][y2] || c1 || c2) {
        if (x2 == x)
          dist[x2][y2] = dist[x][y] + curr_w;
        else
          dist[x2][y2] = dist[x][y] - curr_w;

        pq.push(curr_el);
      }
    }
  }

  dist[n][m] ? cout << dist[n][m] << '\n' : cout << "NO ESCAPE\n";
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
