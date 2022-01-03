#include <iostream>
#include <optional>
#include <queue>

template<typename T>
class Dijkstra {
public:
    struct Edge {
        size_t from;
        size_t to;
        T cost;
    };

    struct Node {
        size_t id;
        int64_t value;
    };
private:
    std::vector<std::optional<int64_t>> distances;
    std::vector<size_t> previous;
    std::vector<std::vector<Edge>> graph;

    static const int EPS = static_cast<const int>(1e-6);


public:
    auto create_graph(const size_t nodes_size) -> void {
        graph.resize(nodes_size);
        previous.resize(nodes_size);
    }

    auto add_edge(const size_t from, const size_t to, const T cost) -> void {
        graph[from].emplace_back(Edge{from, to, cost});
    };

    auto add_edges(const std::vector<Edge> &edges)
    -> void {
        for (const auto &edge : edges) {
            auto[from, to, cost] = edge;
            add_edge(from, to, cost);
        }
    }


    auto run(const size_t start, const size_t end) -> std::optional<int64_t> {
        auto N = graph.size();
        distances.resize(N);
        fill(distances.begin(), distances.end(), std::optional<int64_t>{});
        distances[start] = 0;

        auto compare = [](Node left, Node right) {
            if (std::abs(left.value - right.value) < EPS)return 0;
            return (left.value - right.value) > 0 ? 1 : -1;
        };

        std::priority_queue<Node, std::vector<Node>, decltype(compare)> pq(compare);
        pq.push(Node{start, 0});

        bool visited[N];
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            visited[node.id] = true;

            if (distances[node.id] < node.value) continue;

            for (const auto &edge : graph[node.id]) {
                if (visited[edge.to]) continue;

                auto new_distance = *distances[edge.from] + edge.cost;
                if (!distances[edge.to] || new_distance < distances[edge.to]) {
                    previous[edge.to] = edge.from;
                    distances[edge.to] = new_distance;
                    pq.push(Node{edge.to, *distances[edge.to]});
                }
            }
            if (node.id == end) return distances[end];
        }
        return std::nullopt;
    }

    auto reconstruct_path(const size_t start, const size_t end) -> std::vector<size_t> {
        std::vector<size_t> path{};
        auto dist = run(start, end);
        if (!dist.has_value()) return path;
        for (size_t i = end; i >= start; i = previous[i]) {
            path.push_back(i);
            if (i == start || i < 0 || i > graph.size()) break;
        }
        reverse(path.begin(), path.end());
        return path;
    }

};

auto main() -> int {
    Dijkstra<int> dijkstra{};
    dijkstra.create_graph(9);

    std::vector<decltype(dijkstra)::Edge> edges{
            {0, 1, 1},
            {1, 2, 1},
            {2, 4, 1},
            {4, 3, 3},
            {3, 2, 1},
            {1, 5, 4},
            {1, 6, 4},
            {5, 6, 5},
            {6, 7, 4},
            {5, 7, 3},
    };
    dijkstra.add_edges(edges);
    auto distance = dijkstra.run(0, 3);
    !distance ? std::cout << "Unreachable\n" : std::cout << "Distance: " << *distance << '\n';
    auto path = dijkstra.reconstruct_path(0, 3);
    std::cout << "Path:";
    for (auto edge : path)
        std::cout << " -> " << edge;
    std::cout << '\n';
}