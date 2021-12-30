#include <cstdlib>
#include <functional>
#include <iostream>
#include <optional>
#include <vector>

template <typename T> class BellmanFord {
  using optional_ref = std::optional<std::reference_wrapper<T>>;

 private:
  struct Edge {
    T from, to;
    T cost;
    Edge(T f, T t, T c) : from(f), to(t), cost(c) {}
  };
  std::vector<std::vector<Edge>> graph;

 public:
  auto check_node(T n) -> std::optional<T> { std::cout << n; }

  auto create_graph(const size_t N) -> void { graph.resize(N); };

  auto add_edge(T from, T to, T cost) -> void {
    graph[static_cast<size_t>(from)].push_back(Edge(from, to, cost));
  }

  auto get_distances(size_t start) -> std::vector<optional_ref> {
    auto V = graph.size();
    std::vector<optional_ref> dist(V);
    fill(dist.begin(), dist.end(), optional_ref{std::nullopt});
    dist[start]->get() = 0;

    for (size_t i = 0; i < V - 1; ++i) {
      for (const auto &edges : graph) {
        for (const auto &edge : edges) {
          auto from_i = static_cast<size_t>(edge.from);
          auto to_i = static_cast<size_t>(edge.to);
          T _{};
          if (dist[to_i]->get() == _ ||
              dist[from_i]->get() + edge.cost < dist[to_i]->get()) {
            dist[to_i]->get() = dist[from_i]->get() + edge.cost;
          }
        }
      }
    }

    for (size_t i = 0; i < V - 1; ++i) {
      for (const auto &edges : graph) {
        for (const auto &edge : edges) {
          auto from_i = static_cast<size_t>(edge.from);
          auto to_i = static_cast<size_t>(edge.to);
          T _{};
          if (dist[from_i]->get() + edge.cost < dist[to_i]->get())
            dist[to_i]->get() = _;
        }
      }
    }

    return dist;
  }
};

// Checks if node is in negative cycle

auto main() -> int {
  BellmanFord<int> bellman_ford;
  bellman_ford.create_graph(10);
  bellman_ford.add_edge(0, 1, 4);
  bellman_ford.add_edge(0, 6, 2);
  bellman_ford.add_edge(1, 1, -1);
  bellman_ford.add_edge(1, 2, 3);
  bellman_ford.add_edge(6, 4, 2);
  bellman_ford.add_edge(2, 3, 3);
  bellman_ford.add_edge(2, 4, 1);
  bellman_ford.add_edge(3, 5, -2);
  bellman_ford.add_edge(4, 5, 2);
  auto distances = bellman_ford.get_distances(0);
  for (const auto &dist : distances) {
    std::cout << dist->get() << '\n';
  }
  return EXIT_SUCCESS;
}
