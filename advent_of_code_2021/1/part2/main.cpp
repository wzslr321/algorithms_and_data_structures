#include <climits>
#include <iostream>
#include <tuple>

auto main() -> int {
  int larger = 0;
  int prev = INT_MAX;
  int st, nd, rd;
  std::cin >> st >> nd >> rd;
  while (std::cin) {
    auto trio = std::make_tuple(st, nd, rd);
    auto sum = std::get<0>(trio) + std::get<1>(trio) + std::get<2>(trio);
    if (sum > prev) ++larger;
    prev = sum;
    int next;
    std::cin >> next;
    if (next == 1) break;
    st = nd;
    nd = rd;
    rd = next;
  }
  std::cout << larger << '\n';

  return 0;
}
