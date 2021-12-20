#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int from;
  int to;
  explicit Edge(int v) : from(v) {}
};

int main() {
  int n, s;
  cin >> n >> s;
  vector<Edge> graph;
  int v[2 * n];
  for (int i = 0; i < 2 * n; ++i) {
    cin >> v[i];
  }
  if (v[0] == 0) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (v[i] == 1) {
      auto edge = Edge(i);
      auto change = edge;
      bool can_change = false;
      if (v[n + i] == 1) {
        change.to = n + i;
        bool can_change = true;
      }
      while (i < n - 1) {
        if (v[i + 1] == 1) {
          edge.to = i + 1;
          graph.push_back(edge);
          break;
        }
        ++i;
      }
      if (can_change) {
        graph.push_back(change);
      }
    }
  }
  for (int i = 2 * n - 1; i >= n; --i) {
    if (v[i] == 1) {
      auto edge = Edge(i);
      auto change = edge;
      while (i > n + 1) {
        if (v[i - 1] == 1) {
          edge.to = i - 1;
          graph.push_back(edge);
          break;
        }
        --i;
      }
    }
  }
  queue<Edge> qq;
  if (graph.size() > 0) qq.push(graph[0]);
  if (graph.size() > 1) qq.push(graph[1]);
  while (qq.size() > 0) {
    auto curr = qq.front();
    qq.pop();
    if (curr.to == s - 1 || curr.to == n + s - 1) {
      cout << "YES\n";
      return 0;
    }
    for (int i = 0; i < graph.size(); ++i) {
      if (graph[i].from == curr.to) {
        qq.push(graph[i]);
      }
    }
  }
  cout << "NO\n";
}
