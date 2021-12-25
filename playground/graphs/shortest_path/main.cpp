#include <cstdlib>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

struct Edge {
  int from;
  int to;
  int cost;
  Edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

auto bfs(std::unordered_map<int, std::vector<Edge>> &graph, int start) -> void;

auto add_edge(std::unordered_map<int, std::vector<Edge>> &graph, int from,
              int to, int cost) -> void;

auto main() -> int {
  std::unordered_map<int, std::vector<Edge>> graph;
  add_edge(graph, 1, 5, 3);
  add_edge(graph, 1, 4, 5);
  add_edge(graph, 1, 2, 7);
  add_edge(graph, 2, 4, 9);
  bfs(graph, 1);
  return EXIT_SUCCESS;
}

auto bfs(std::unordered_map<int, std::vector<Edge>> &graph, int start) -> void {
  std::unordered_map<int, bool> visited;
  visited[start] = true;
  std::queue<int> qq;
  qq.push(start);
  while (qq.size() > 0) {
    auto current = qq.front();
    qq.pop();

    for (const auto &edge : graph[current]) {
      std::cout << edge.from << ' ' << edge.to << ' ' << edge.cost << '\n';
      if (!visited[edge.to]) {
        visited[edge.to] = true;
        qq.push(edge.to);
      }
    }
  }
}

auto add_edge(std::unordered_map<int, std::vector<Edge>> &graph, int from,
              int to, int cost) -> void {
  graph[from].push_back(Edge(from, to, cost));
}
