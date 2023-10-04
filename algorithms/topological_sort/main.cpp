#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>

class TopologicalSort {
public:
    struct Edge {
        size_t from;
        size_t to;
        int64_t cost;
    };

private:
    std::vector<bool> visited{};
    std::vector<int> ordering{};
    std::vector<std::vector<Edge>> graph;

    auto dfs(size_t index, const size_t at) -> size_t {
        visited[at] = true;

        if (at < graph.size()) {
            for (const auto edge : graph[at]) {
                if (!visited[edge.to]) index = dfs(index, edge.to);
            }
        }

        ordering[index] = static_cast<int>(at);
        return index - 1;
    }

public:
    auto sort() -> void {
        const auto N = graph.size();
        ordering.resize(N);
        visited.resize(N);

        size_t index = N - 1;
        for (size_t at = 0; at < N; ++at) {
            if (!visited[at]) index = dfs(index, at);
        }
    }

    auto dag_shortest_path(const size_t start) -> std::vector<std::optional<int64_t>> {
        const auto N = graph.size();
        sort(); // fill ordering vec
        std::vector<std::optional<int64_t>> distances{};
        distances.resize(N);
        distances[start] = 0LL;

        for (size_t i = 0; i < N; ++i) {
            if (i >= ordering.size()) continue;
            auto node_index = static_cast<size_t>(ordering[i]);
            if (node_index >= graph.size()) continue;

            for (const auto &edge : graph[node_index]) {
                auto new_distance = *distances[node_index] + edge.cost;
                if (!distances[edge.to]) distances[edge.to] = new_distance;
                else distances[edge.to] = std::min(*distances[edge.to], new_distance);
            }
        }

        return distances;
    }

    auto get_ordering() -> std::vector<int> {
        return ordering;
    }

    auto create_graph(const size_t vertices_count) -> void {
        graph.resize(vertices_count);
    };

    auto add_edge(const size_t from, const size_t to, const int64_t cost) -> void {
        graph[from].emplace_back(Edge{from, to, cost});
    };

    auto add_edges(const std::vector<Edge> &edges) -> void {
        for (const auto &edge : edges) {
            auto[from, to, cost] = edge;
            add_edge(from, to, cost);
        }
    }
};

auto main() -> int {
    TopologicalSort topological_sort{};
    size_t graph_size = 7;
    topological_sort.create_graph(graph_size);
    std::vector<decltype(topological_sort)::Edge> edges{
            {0, 1, 3},
            {0, 2, 2},
            {0, 5, 3},
            {1, 3, 1},
            {1, 2, 6},
            {2, 3, 1},
            {2, 4, 10},
            {3, 4, 5},
            {5, 4, 7},
    };
    topological_sort.add_edges(edges);
    topological_sort.sort();
    auto sorted_vector = topological_sort.get_ordering();
    for (const auto el : sorted_vector) {
        std::cout << el << ' ';
    }
    std::cout << '\n';

    size_t start = 0;
    auto shortest_paths = topological_sort.dag_shortest_path(start);
    for (const auto el : shortest_paths) {
        std::cout << *el << ' ';
    }

    std::cout << '\n';
}
