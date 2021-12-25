// this one is unsolved yet

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

struct Edge {
  int from;
  int to;
  Edge(int f, int t) : from(f), to(t) {}
};

bool bfs(unordered_map<int, vector<Edge>> &graph, int start, int n) {
  bool visited[n];
  for (int i = 0; i < n; ++i) {
    visited[i] = false;
  }
  queue<int> qq;
  qq.push(start);
  visited[start] = true;
  static int visited_count = 1;
  while (qq.size() > 0) {
    auto current = qq.front();
    qq.pop();
    auto edges = graph[current];
    for (const auto &edge : edges) {
      if (!visited[edge.to]) {
        visited[edge.to] = true;
        ++visited_count;
        qq.push(edge.to);
      } else {
        for (const auto &edge2 : graph[edge.to]) {
          for (const auto &edge3 : graph[edge2.to]) {
            if (edge3.to == current && edge2.to != current &&
                edge.to != current)
              return true;
          }
        }
      }
    }
  }
  if (visited_count < n) {
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) return bfs(graph, i, n);
    }
  }
  return false;
}

int main() {
  int n;
  cin >> n;
  unordered_map<int, vector<Edge>> graph;
  int data[n];
  for (int i = 0; i < n; ++i) {
    cin >> data[i];
  }
  for (int i = 0; i < n; ++i) {
    graph[data[i]].push_back(Edge(data[i], data[data[i] - 1]));
  }

  bfs(graph, 1, n) ? cout << "YES\n" : cout << "NO\n";

  return 0;
}
