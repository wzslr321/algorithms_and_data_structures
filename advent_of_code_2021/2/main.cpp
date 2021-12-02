#include <iostream>

auto main() -> int {
  int x = 0, y = 0;
  while (std::cin) {
    std::string direction;
    std::cin >> direction;
    int val;
    std::cin >> val;
    if (direction == "forward") {
      x += val;
      continue;
    }
    if (direction == "up") {
      y -= val;
      continue;
    }
    if (direction == "down") {
      y += val;
      continue;
    }

    std::cout << x * y << '\n';
    break;
  }

  return 0;
}
