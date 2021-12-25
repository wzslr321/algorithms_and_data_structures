#include <cstdlib>
#include <iostream>
#include <vector>

// Least significant bit
#define LSB(i) ((i) & -(i))

struct fenwick_tree {
 private:
  std::vector<int> tree;
  int N;

 public:
  explicit fenwick_tree(std::vector<int> values) {
    if (values.size() < 1) return;
    N = values.size();
    values[0] = 0;

    tree = values;

    for (int i = 1; i < N; ++i) {
      if (i + LSB(i) < N) tree[i + LSB(i)] += tree[i];
    }
  }

  auto prefix_sum(int right) -> int64_t {
    int64_t sum = tree[0];
    for (; right != 0; right -= LSB(right))
      sum += tree[right];
    return sum;
  }

  auto sum(int left, int right) -> int64_t {
    return prefix_sum(right) - prefix_sum(left - 1);
  }

  auto get_at(int i) -> int64_t { return sum(i, i); }

  auto add_at(int i, int val) -> void {
    while (i < N) {
      tree[i] += val;
      i += LSB(i);
    }
  }

  auto set_to(int i, int val) -> void { add_at(i, val - sum(i, i)); }
};

auto main() -> int {
  // must be one based
  std::vector<int> values{0, 5, 4, 12, 8, 1, 2};

  fenwick_tree fwt(values);

  std::cout << "Before set: " << fwt.prefix_sum(6) << '\n';
  fwt.set_to(3, 0);
  std::cout << fwt.get_at(3) << '\n';
  std::cout << "After set: " << fwt.prefix_sum(6) << '\n';
  std::cout << "Sum: <2,4): " << fwt.sum(2, 6) << '\n';

  return EXIT_SUCCESS;
}
