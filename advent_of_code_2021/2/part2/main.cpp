#include <iostream>

auto main() -> int {
  int x = 0, y = 0, aim = 0;
  while (std::cin) {
    std::string direction;
    std::cin >> direction;
    if (direction == "1") break;
    int val;
    std::cin >> val;
    if (direction == "forward") {
      x += val;
      y += aim * val;
      continue;
    }
    if (direction == "up") {
      aim -= val;
      continue;
    }
    if (direction == "down") {
      aim += val;
      continue;
    }
  }
  std::cout << x * y << '\n';

  return 0;
}
