#include <array>
#include <cstdlib>
#include <iostream>
#include <vector>

auto knapsack(const size_t capacity, const std::vector<int> &weights,
              const std::vector<int> &values, std::vector<int> &out) -> int {

  const size_t N = weights.size();

  std::vector<std::vector<int>> matrix(N + 1, std::vector<int>(capacity + 1));

  for (size_t i = 1; i <= N; i++) {
    int weight = weights[i - 1];
    int value = values[i - 1];

    for (int j = 1; j <= capacity; j++) {
      matrix[i][j] = matrix[i - 1][j];

      if (j >= weight && matrix[i - 1][j - weight] + value > matrix[i][j])
        matrix[i][j] = matrix[i - 1][j - weight] + value;
    }
  }

  int cap = capacity;
  for (size_t i = N; i > 0; --i) {
    if (matrix[i][cap] != matrix[i - 1][cap]) {
      out.push_back(i - 1);
      cap -= weights[i - 1];
    }
  }

  return matrix[N][capacity];
}

auto main() -> int {
  const size_t capacity = 25;
  const std::vector<int> weights{1, 5, 12, 4, 6, 7};
  const std::vector<int> values{0, 10, 18, 4, 2, 5};
  std::vector<int> used_items{};
  auto result = knapsack(capacity, weights, values, used_items);

  std::cout << "Result: " << result << '\n';

  for (size_t i = 0; i < used_items.size(); ++i) {
    std::cout << "Used item: " << values[used_items[i]] << '\n';
  }

  return EXIT_SUCCESS;
}
