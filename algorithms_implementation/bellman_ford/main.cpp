#include <cstdlib>
#include <functional>
#include <iostream>
#include <optional>
#include <vector>
#include <limits>

struct Edge {
    int from, to;
    double cost;

    Edge(int f, int t, double c) : from(f), to(t), cost(c) {}
};

auto create_graph(const size_t N) -> std::vector<std::vector<Edge>> {
    auto graph = std::vector<std::vector<Edge>>{};
    graph.resize(N);
    return graph;
};


auto add_edge(std::vector<std::vector<Edge>> &graph, int from, int to, int cost) -> void {
    graph[static_cast<size_t>(from)].push_back(Edge(from, to, cost));
};

auto get_distances(std::vector<std::vector<Edge>> &graph, int V, int start) -> std::vector<std::optional<int>> {
    std::vector<std::optional<int>> dist;
    dist.resize(V);
    fill(dist.begin(), dist.end(), std::optional<int>{std::nullopt});
    dist[start] = 0.;

    for (auto i = 0; i < V - 1; i++) {
        for (const auto &edges : graph) {
            for (const auto &edge : edges) {
                if (!dist[edge.to].has_value() || *dist[edge.from] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = *dist[edge.from] + edge.cost;
                }
            }
        }
    }

    for (auto i = 0; i < V - 1; i++) {
        for (const auto &edges : graph) {
            for (const auto &edge : edges) {
                if (dist[edge.from] == std::nullopt || *dist[edge.from] + edge.cost < dist[edge.to])
                    dist[edge.to] = std::optional<int>{std::nullopt};
            }
        }
    }

    return dist;
}

// Checks if node is in negative cycle

auto main() -> int {
    auto graph = create_graph(9);
    add_edge(graph, 0, 1, 1.);
    add_edge(graph, 1, 2, 1.);
    add_edge(graph, 2, 4, 1.);
    add_edge(graph, 4, 3, -3.);
    add_edge(graph, 3, 2, 1.);
    add_edge(graph, 1, 5, 4.);
    add_edge(graph, 1, 6, 4.);
    add_edge(graph, 5, 6, 5.);
    add_edge(graph, 6, 7, 4.);
    add_edge(graph, 5, 7, 3.);
    auto distances = get_distances(graph, 9, 0);
    for (const auto &dist : distances) {
        if (dist == std::nullopt)
            std::cout << "INFINITY\n";
        else
            std::cout << *dist << '\n';
    }
    return EXIT_SUCCESS;
}