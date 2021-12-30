#include <cstdlib>
#include <iostream>
#include <optional>
#include <tuple>
#include <vector>

template<typename T>
class BellmanFord {
private:
    struct Edge {
        size_t from, to;
        T cost;

        Edge(size_t f, size_t t, T c) : from(f), to(t), cost(c) {}
    };

protected:
    std::vector<std::vector<Edge>> graph;
    std::vector<std::optional<T>> distances;

private:
    auto find_shortest_paths(size_t start) -> void {
        auto vertices_size = graph.size();
        distances.resize(vertices_size);
        fill(distances.begin(), distances.end(), std::optional<T>{std::nullopt});
        distances[start] = 0.;

        for (size_t i = 0; i < vertices_size - 1; i++) {
            for (const auto &edges : graph) {
                for (const auto &edge : edges) {
                    if (!distances[edge.to].has_value() ||
                        *distances[edge.from] + edge.cost < distances[edge.to]) {
                        distances[edge.to] = *distances[edge.from] + edge.cost;
                    }
                }
            }
        }

        for (size_t i = 0; i < vertices_size - 1; i++) {
            for (const auto &edges : graph) {
                for (const auto &edge : edges) {
                    if (distances[edge.from] == std::nullopt ||
                        *distances[edge.from] + edge.cost < distances[edge.to])
                        distances[edge.to] = std::optional<T>{std::nullopt};
                }
            }
        }
    }

public:
    auto create_graph(const size_t vertices_count) -> void {
        graph.resize(vertices_count);
    };

    auto add_edge(const size_t from, const size_t to, const T cost) -> void {
        graph[from].push_back(Edge(from, to, cost));
    };

    auto add_edges(const std::vector<std::tuple<size_t, size_t, T>> &edges)
    -> void {
        for (const auto &edge : edges) {
            auto[from, to, cost] = edge;
            add_edge(from, to, cost);
        }
    }

    auto run(const size_t start) -> std::vector<std::optional<int>> {
        find_shortest_paths(start);
        return distances;
    }
};

auto main() -> int {
    BellmanFord<int> bellman_ford{};
    size_t graph_size = 9;
    bellman_ford.create_graph(graph_size);
    std::vector<std::tuple<size_t, size_t, int>> edges{
            std::make_tuple(0, 1, 1), std::make_tuple(1, 2, 1),
            std::make_tuple(2, 4, 1), std::make_tuple(4, 3, -3),
            std::make_tuple(3, 2, 1), std::make_tuple(1, 5, 4),
            std::make_tuple(1, 6, 4), std::make_tuple(5, 6, 5),
            std::make_tuple(6, 7, 4), std::make_tuple(5, 7, 3),
    };
    bellman_ford.add_edges(edges);

    size_t start = 0;
    auto distances = bellman_ford.run(start);

    for (const auto &dist : distances) {
        if (dist == std::nullopt)
            std::cout << "INFINITY\n";
        else
            std::cout << *dist << '\n';
    }
    return EXIT_SUCCESS;
}
