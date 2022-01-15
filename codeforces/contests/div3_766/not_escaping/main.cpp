#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back

#define LPI(i, a, b, d) for (int(i) = a; (i) < (int)(b); (i) += (d))

using PI = pair<int, int>;

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

void print(PI p, int i, unordered_map<PI, vector<pair<PI, int>>> &graph);

auto solve() -> void {
  auto dist = unordered_map<PI, ll>();
  auto graph = unordered_map<PI, vector<pair<PI, int>>>();
  int n, m, k, a, b, c, d, h;
  priority_queue<PI> pq;
  PI curr, curr_el;
  int curr_w;
  cin >> n >> m >> k;
  vector<int> hx(n + 1);
  LPI(i, 1, n + 1, 1) cin >> hx[i];

  LPI(i, 0, k, 1) {
    cin >> a >> b >> c >> d >> h;
    graph[{a, b}].PB({{c, d}, h});
  }
  // get edges on first floor
  LPI(i, 2, m + 1, 1) {
    auto current = graph[{1, i}];
    if (!current.empty()) {
      graph[{1, 1}].PB({{1, i}, abs(1 - i) * hx[1]});
    }
  }

  pq.push({1, 1});
  while (!pq.empty()) {
    curr = pq.top();
    pq.pop();
    if (graph[curr].empty()) {
      LPI(i, 1, m + 1, 1) {
        auto current = graph[{curr.first, i}];
        if (!current.empty() || (curr.first == n && i == m)) {
          graph[curr].PB(
              {{curr.first, i}, abs(curr.second - i) * hx[curr.first]});
        }
      }
    }
    LPI(i, 0, graph[curr].size(), 1) {
      // print(curr, i, graph);
      curr_el = graph[curr][i].first;
      curr_w = graph[curr][i].second;
      if (!dist[curr_el] || dist[curr] + curr_w < dist[curr_el]) {
        if (curr_el.first == curr.first) {
          dist[curr_el] = dist[curr] + curr_w;
        } else {
          dist[curr_el] = dist[curr] - curr_w;
        }

        pq.push(curr_el);
      }
    }
  }

  dist[{n, m}] ? cout << dist[{n, m}] << '\n' : cout << "NO ESCAPE\n";
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

void print(PI p, int i, unordered_map<PI, vector<pair<PI, int>>> &graph) {
  cout << "From: (" << p.first << ',' << p.second << ") to: ("
       << graph[p][i].first.first << ',' << graph[p][i].first.second
       << ") with cost of: " << graph[p][i].second << '\n';
}
