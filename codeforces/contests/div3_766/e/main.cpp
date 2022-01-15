#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

namespace std {
template <typename T, typename U> struct hash<std::pair<T, U>> {
  auto operator()(const std::pair<T, U> &pair) const noexcept {
    auto const hash_t = std::hash<T>{}(pair.first);
    auto const hash_u = std::hash<U>{}(pair.second);
    return hash_t ^ hash_u;
  }
};
} // namespace std

int n, m, k;
priority_queue<pair<int, int>> pq;
pair<int, int> curr, curr_el;
int curr_w;
auto dist = unordered_map<pair<int, int>, ll>();

auto graph = unordered_map<pair<int, int>, vector<pair<pair<int, int>, int>>>();
unordered_map<int, int> hx;

auto solve() -> void {
  cin >> n >> m >> k;
  LPI(i, 1, n + 1, 1) {
    int tmp;
    cin >> tmp;
    hx[i] = tmp;
  }

  int a, b, c, d, h;
  cin >> a >> b >> c >> d >> h;
  graph[{1, 1}].PB({{b, c}, abs(1 - d) * hx[1]});

  LPI(i, 1, k, 1) {
    int a, b, c, d, h;
    cin >> a >> b >> c >> d >> h;
    graph[{a, b}].PB({{c, d}, h});
  }
  pq.push({1, 1});
  while (pq.size() > 0) {
    curr = pq.top();
    pq.pop();
    if (graph[curr].size() == 0) {
      // szukaj drabin z buta
      LPI(i, 1, m + 1, 1) {
        auto obc = graph[{curr.first, i}];
        if (obc.size() > 0 || (curr.first == n && i == m)) {
          graph[curr].PB(
              {{curr.first, i}, abs(curr.second - i) * hx[curr.first]});
        }
      }
    }
    LPI(i, 0, graph[curr].size(), 1) {
      curr_el = graph[curr][i].first;
      curr_w = graph[curr][i].second;
      if (!dist[curr_el] || dist[curr] + curr_w < dist[curr_el]) {
        // zabierz hp bo z buta/ dodaj bo po drabinie (?);
        dist[curr_el] = dist[curr] + curr_w;
        pq.push(curr_el);
      }
    }
  }

  dist[{n, m}] ? cout << dist[{n, m}] << '\n' : cout << "NO ESCAPE\n";
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int _ = 1;
  cin >> _;
  while (_--)
    solve();

  return 0;
}
